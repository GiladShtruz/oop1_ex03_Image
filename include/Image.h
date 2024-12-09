#pragma once
#include "ImageDataStructure.h"
#include "Pixel.h"
class Image {
public:
	Image():m_Height(0),m_Height(0),m_image(0)
	Image(int height, int width);
	Image(int height, int width, Pixel pixel);
	print();

private:
	ImageDataStructure m_image;
	unsigned int m_Height;
	unsigned int m_Width;
};