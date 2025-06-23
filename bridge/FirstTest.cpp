#include "FirstTest.h"
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace System;

void FirstTest::ping() {
	std::cout << "got a ping" << std::endl;
	cv::Mat image = cv::imread("C:\\temp\\car.jpg");
	cv::imshow("testing", image);
	std::cout << "image from path read" << std::endl;
}

void FirstTest::transfer(Image^ img)
{
	std::cout << "got an image, converting..." << std::endl;
}
