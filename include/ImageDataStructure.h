#pragma once
#include "Pixel.h"

class ImageDataStructure {

public:
	ImageDataStructure();
	~ImageDataStructure();
	ImageDataStructure(int height, int width);
	ImageDataStructure(int height, int width, Pixel pixel);
private:
	Pixel** m_image;
	unsigned int m_Height;
	unsigned int m_Width;
};