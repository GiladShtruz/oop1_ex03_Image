#pragma once
#include "Pixel.h"
//class Image;
class ImageDataStructure {

public:
	ImageDataStructure();
	ImageDataStructure(int height, int width);
	ImageDataStructure(int height, int width, Pixel pixel);
	void paintPixel(int row, int col, Pixel pixel);
	void paintAll(ImageDataStructure imageDataStructure);
	Pixel getPixel(int row, int col) const;



	//Pixel** cloneImage(const ImageDataStructure& other);
	//Pixel** whiteImage();
	//~ImageDataStructure();
	//Pixel** colorImage(Pixel pixel);
	

private:
	Pixel** m_pixels;
	int m_height;
	int m_width;
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