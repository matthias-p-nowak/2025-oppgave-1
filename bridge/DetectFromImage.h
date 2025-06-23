#pragma once

using namespace System::Drawing;
using namespace System;

public ref class DetectFromImage
{
public:
	String^ modelPath;
	DetectFromImage(String^ mp) { modelPath = mp; };
	Bitmap^ DetectAndAnnotate(Bitmap^ source);
};

