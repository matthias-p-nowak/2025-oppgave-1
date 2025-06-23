#include "MigrateImage.h"
using namespace System::Diagnostics;
using namespace System::Drawing::Imaging;

cv::Mat MigrateImage::fromBitmap(Bitmap^ bitmap)
{
	Debug::WriteLine("got an image");
	Rectangle rect = Rectangle(0, 0, bitmap->Width, bitmap->Height);
	BitmapData^ bmpData = bitmap->LockBits(rect, ImageLockMode::ReadOnly, PixelFormat::Format24bppRgb);

	// Create cv::Mat using the pixel buffer
	cv::Mat mat(bitmap->Height, bitmap->Width, CV_8UC3, bmpData->Scan0.ToPointer(), bmpData->Stride);

	// Clone to make a deep copy (bitmap may go out of scope)
	cv::Mat result = mat.clone();

	// Unlock the bits
	bitmap->UnlockBits(bmpData);
	return result;
}

Bitmap^ MigrateImage::toBitmap(cv::Mat matrix)
{
	auto w = matrix.cols;
	auto h = matrix.rows;
	auto resultBitmap = gcnew Bitmap(w, h, PixelFormat::Format24bppRgb);
	auto rect = Rectangle(0, 0, w, h);
	auto bmpData = resultBitmap->LockBits(rect, ImageLockMode::ReadWrite, PixelFormat::Format24bppRgb);
	// Copy raw data (assumes stride is compatible)
	uchar* srcData = matrix.data;
	uchar* dstData = (uchar*)bmpData->Scan0.ToPointer();

	int stride = bmpData->Stride;
	for (int y = 0; y < h; ++y)
	{
		memcpy(dstData + y * stride, srcData + y * w * 3, w * 3);
	}
	resultBitmap->UnlockBits(bmpData);
	return resultBitmap;
}
