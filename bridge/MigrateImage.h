#pragma once
#include <opencv2/opencv.hpp>

using namespace System::Drawing;
using namespace System;

ref class MigrateImage
{
public:
	static cv::Mat fromBitmap(Bitmap^ bitmap);
	static Bitmap^ toBitmap(cv::Mat matrix);
};

