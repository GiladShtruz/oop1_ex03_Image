#include "ImageDataStructure.h"


ImageDataStructure::ImageDataStructure()
:mHeight(0), mWidth(0), mImage(nullptr){}

ImageDataStructure::ImageDataStructure(int height, int width)
	:mHeight(height), mWidth(width), mImage(colorImage(Pixel(WHITE))){}

ImageDataStructure::ImageDataStructure(int height, int width, Pixel pixel)
	:mHeight(height), mWidth(width), mImage(colorImage(pixel)){}

Pixel** ImageDataStructure::cloneImage(const ImageDataStructure& other)
{
	Pixel** newImage = new Pixel * [other.mHeight];
	for (int rowIndex = 0; rowIndex < other.mHeight; rowIndex++)
	{
		newImage[rowIndex] = new Pixel[other.mHeight];
		for (int colIndex = 0; colIndex < other.mHeight; colIndex++)
		{
			newImage[rowIndex][colIndex] = other.mImage[rowIndex][colIndex];
		}
	}
	return newImage;
}

Pixel** ImageDataStructure::whiteImage()
{
	return colorImage(WHITE);
}

ImageDataStructure::~ImageDataStructure()
{
	for (int rowIndex = 0; rowIndex < this->mHeight; rowIndex++)
	{
		delete[] this->mImage[rowIndex];
	}
	delete[] this->mImage;
}

Pixel** ImageDataStructure::colorImage(Pixel pixel)
{
	Pixel** newPixel = new Pixel * [mHeight];
	for (int rowIndex = 0; rowIndex < mHeight; rowIndex++)
	{
		newPixel[rowIndex] = new Pixel[mWidth];
		for (int colIndex = 0; colIndex < mWidth; colIndex++)
		{
			newPixel[rowIndex][colIndex] = pixel.getColor();
		}
	}
	return newPixel;
}



























//Pixel** ImageDataStructure::whiteImage(int height, int width)
//{
//	return colorImage(height, width, WHITE);
//}
//
//Pixel** ImageDataStructure::colorImage(int height, int width, Pixel pixel)
//{
//	Pixel** newPixel = new Pixel * [height];
//	for (int rowIndex = 0; rowIndex < height; rowIndex++)
//	{
//		newPixel[rowIndex] = new Pixel[width];
//		for (int colIndex = 0; colIndex < width; colIndex++)
//		{
//			newPixel[rowIndex][colIndex] = pixel.getColor();
//		}
//	}
//	return newPixel;
//}
//
//ImageDataStructure::ImageDataStructure()
//:mHeight(0), mWidth(0), mImage(nullptr){}
//
//ImageDataStructure::ImageDataStructure(int height, int width)
//{
//}


