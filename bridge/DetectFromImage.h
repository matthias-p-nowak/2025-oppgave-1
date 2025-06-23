#pragma once

using namespace System::Drawing;

public ref class DetectFromImage
{
public:
	Bitmap^ DetectAndAnnotate(Bitmap^ source);
};

