#include "FirstTest.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include "MigrateImage.h"

using namespace System;
using namespace System::Diagnostics;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;


Bitmap^ FirstTest::transfer(Bitmap^ bmp)
{
	Debug::WriteLine("got an image");

	auto imageMatrix = MigrateImage::fromBitmap(bmp);

	auto imgw = imageMatrix.cols / 2;
	auto imgh = imageMatrix.rows / 2;
	cv::Point center(imgw, imgh);
	cv::Size axes(imgw / 2, imgh / 2);
	cv::Scalar red(0, 0, 255);
	cv::ellipse(imageMatrix, center, axes, 0, 0, 360, red, 2);
	//cv::imshow("redigert", imageMatrix);
	return MigrateImage::toBitmap(imageMatrix);

}
