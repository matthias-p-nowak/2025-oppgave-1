#include <onnxruntime_cxx_api.h>
#include "DetectFromImage.h"
#include "MigrateImage.h"

#include "YoloCpp/YOLO11.hpp"

using namespace System::Diagnostics;
using namespace System;

std::string String2string(String^ src) {
	using namespace Runtime::InteropServices;
	const char* chars;
	try {
		chars =
			(const char*)(Marshal::StringToHGlobalAnsi(src)).ToPointer();
		return chars;
	}
	finally {
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}
}

Bitmap^ DetectFromImage::DetectAndAnnotate(Bitmap^ source)
{
	auto sourceMatrix = MigrateImage::fromBitmap(source);
	Debug::WriteLine("running detection");
	std::string mp = String2string(modelPath);
	auto modelFile = mp + "/model.onnx";
	auto labelFile = mp + "/coco.names";
	Debug::WriteLine("initializing detector");
	YOLO11Detector detector(modelFile, labelFile, false);
	Debug::WriteLine("running detector");
	std::vector<Detection> results = detector.detect(sourceMatrix);
	// Draw bounding boxes on the image
	Debug::WriteLine("drawing boxes");
	detector.drawBoundingBox(sourceMatrix, results); // simple bbox drawing
	// detector.drawBoundingBoxMask(image, results); // Uncomment for mask drawing
	Debug::WriteLine("returning results");
	return MigrateImage::toBitmap(sourceMatrix);
}
