#include "ImageDataStructure.h"


ImageDataStructure::ImageDataStructure()
	:mHeight(0), mWidth(0)
{
	mPixels = nullptr;
}

ImageDataStructure::ImageDataStructure(int height, int width)
	:mHeight(height), mWidth(width)
{
	mPixels = new Pixel* [height];
	for (int rowIndex = 0; rowIndex < height; rowIndex++)
	{
		mPixels[rowIndex] = new Pixel[width];	
		for (int colIndex = 0; colIndex < width; colIndex++)
		{
			mPixels[rowIndex][colIndex] = Pixel(WHITE);
		}
	}
}
ImageDataStructure::ImageDataStructure(const ImageDataStructure& other)
	:mHeight(other.mHeight), mWidth(other.mWidth)
{
	mPixels = cloneImage(other);
}
ImageDataStructure& ImageDataStructure::operator=(const ImageDataStructure& other)
{
	mHeight = other.mHeight;
	mWidth = other.mWidth;
	if (this != &other)
	{
		if (this->mPixels != nullptr)
		{
		   cleanPixel();
		}
	}
	mPixels = cloneImage(other);
	return *this;
}
//ImageDataStructure& ImageDataStructure::operator=(const ImageDataStructure& other)
// 
//{
//	if (this != &other)
//	{
//		this->cleanPixel();
//		ImageDataStructure temp(other);
//		return temp;
//	}
//	ImageDataStructure temp = ImageDataStructure(other);
//	return temp;
//}
ImageDataStructure::~ImageDataStructure()
{
	cleanPixel();
}
//
//void ImageDataStructure::paintPixel(int row, int col, Pixel pixel)
//{
//	m_pixels[row][col] = pixel;
//}

/*void ImageDataStructure::paintAll(ImageDataStructure imageDataStructure)
{
	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			paintPixel(i, j, imageDataStructure.getPixel(i, j));
		}
	}
}*/

//Pixel ImageDataStructure::getPixel(int row, int col) const
//{
//	return m_pixels[row][col];
//}

Pixel** ImageDataStructure::cloneImage(const ImageDataStructure& other)
{
	Pixel** newImage = new Pixel * [other.mHeight];
	for (int rowIndex = 0; rowIndex < other.mHeight; rowIndex++)
	{
		newImage[rowIndex] = new Pixel[other.mWidth];
		for (int col = 0; col < other.mWidth; col++)
		{
			newImage[rowIndex][col] = other.mPixels[rowIndex][col];
		}
	}
	return newImage;
}
void ImageDataStructure::cleanPixel()
{
	if (mPixels != nullptr)
	{
		for (int rowIndex = 0; rowIndex < this->mHeight; rowIndex++)
		{
			delete[] mPixels[rowIndex];
		}
		delete[] mPixels;
	}
	mPixels = nullptr;
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


