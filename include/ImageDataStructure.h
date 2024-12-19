#pragma once
#include "Pixel.h"
//class Image;
class ImageDataStructure {

public:
	ImageDataStructure();
	ImageDataStructure(int height, int width);
	ImageDataStructure(const ImageDataStructure& other);
	ImageDataStructure& operator=(const ImageDataStructure& other);
	~ImageDataStructure();
	Pixel** mPixels;

private:
	Pixel** cloneImage(const ImageDataStructure& other);
	void cleanPixel();
	int mHeight;
	int mWidth;
};
