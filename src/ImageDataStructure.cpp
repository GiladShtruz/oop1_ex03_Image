#include "ImageDataStructure.h"


ImageDataStructure::ImageDataStructure()
{
	m_height = 0;
	m_width = 0;
	m_pixels = nullptr;
}

ImageDataStructure::ImageDataStructure(int height, int width)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			Pixel pixel = Pixel(WHITE);
			m_pixels[i][j] = pixel;
		}
	}
	m_height = height;
	m_width = width;
}

ImageDataStructure::ImageDataStructure(int height, int width, Pixel pixel)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			Pixel newPixel = Pixel(pixel.getColor());
			m_pixels[i][j] = newPixel;
		}
	}
	m_height = height;
	m_width = width;
}

void ImageDataStructure::paintPixel(int row, int col, Pixel pixel)
{
	m_pixels[row][col] = pixel;
}

void ImageDataStructure::paintAll(ImageDataStructure imageDataStructure)
{
	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			paintPixel(i, j, imageDataStructure.getPixel(i, j));
		}
	}
}

Pixel ImageDataStructure::getPixel(int row, int col) const
{
	return m_pixels[row][col];
}

//Pixel** ImageDataStructure::cloneImage(const ImageDataStructure& other)
//{
//	Pixel** newImage = new Pixel * [other.mHeight];
//	for (int rowIndex = 0; rowIndex < other.mHeight; rowIndex++)
//	{
//		newImage[rowIndex] = new Pixel[other.mHeight];
//		for (int colIndex = 0; colIndex < other.mHeight; colIndex++)
//		{
//			newImage[rowIndex][colIndex] = other.mImage[rowIndex][colIndex];
//		}
//	}
//	return newImage;
//}
//
//Pixel** ImageDataStructure::whiteImage()
//{
//	return colorImage(WHITE);
//}
//
//ImageDataStructure::~ImageDataStructure()
//{
//	for (int rowIndex = 0; rowIndex < this->mHeight; rowIndex++)
//	{
//		delete[] this->mImage[rowIndex];
//	}
//	delete[] this->mImage;
//}
//
//Pixel** ImageDataStructure::colorImage(Pixel pixel)
//{
//	Pixel** newPixel = new Pixel * [mHeight];
//	for (int rowIndex = 0; rowIndex < mHeight; rowIndex++)
//	{
//		newPixel[rowIndex] = new Pixel[mWidth];
//		for (int colIndex = 0; colIndex < mWidth; colIndex++)
//		{
//			newPixel[rowIndex][colIndex] = pixel.getColor();
//		}
//	}
//	return newPixel;
//}





























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


