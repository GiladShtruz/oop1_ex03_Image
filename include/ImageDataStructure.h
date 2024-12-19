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













//class ImageDataStructure {
//
//public:
//	ImageDataStructure();
//	ImageDataStructure(int height, int width);
//	ImageDataStructure(int height, int width, Pixel pixel);
//	Pixel getPixel()const;
//	void setPixel();
//	~ImageDataStructure();
//
//private:
//	Pixel** cloneImage(const ImageDataStructure& other);
//	Pixel** whiteImage(int height, int width);
//	Pixel** colorImage(int height, int width, Pixel pixel);
//	Pixel** mImage;
//	unsigned int mHeight;
//	unsigned int mWidth;
//};