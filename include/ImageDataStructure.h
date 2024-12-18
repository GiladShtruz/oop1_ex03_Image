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
	//ImageDataStructure(int height, int width, Pixel pixel);
	//void paintPixel(int row, int col, Pixel pixel);
	//void paintAll(ImageDataStructure imageDataStructure);
	//Pixel getPixel(int row, int col) const;



	//Pixel** whiteImage();
	//Pixel** colorImage(Pixel pixel);
	

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