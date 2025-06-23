#include "FirstTest.h"
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace System;
using namespace System::Diagnostics;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;


void FirstTest::transfer(Bitmap^ bmp)
{
	Debug::WriteLine("got an image");
    Rectangle rect = Rectangle(0, 0, bmp->Width, bmp->Height);
    BitmapData^ bmpData = bmp->LockBits(rect, ImageLockMode::ReadOnly, PixelFormat::Format24bppRgb);

    // Create cv::Mat using the pixel buffer
    cv::Mat mat(bmp->Height, bmp->Width, CV_8UC3, bmpData->Scan0.ToPointer(), bmpData->Stride);

    // Clone to make a deep copy (bitmap may go out of scope)
    cv::Mat result = mat.clone();

    // Unlock the bits
    bmp->UnlockBits(bmpData);
    //cv::imshow("transferred", result);
}
