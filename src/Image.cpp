#include "Image.h"
#include "Pixel.h"
#include "ImageDataStructure.h"
#include "iostream"

Image::Image() {
	m_height = 0;
	m_width = 0;
	m_imageDataStructure = ImageDataStructure();
}

Image::Image(int height, int width)
{
	m_height = height;
	m_width = width;
	m_imageDataStructure = ImageDataStructure(height, width);
}

Image::Image(int height, int width, Pixel pixel)
{
	m_height = height;
	m_width = width;
	m_imageDataStructure = ImageDataStructure(height, width, pixel);
}

unsigned int Image::getWidth() const {
	return m_width;
}

unsigned int Image::getHeight() const
{
	return m_height;
}


bool operator==(const Image& a, const Image& b) {
	bool sameSize = a.getWidth() == b.getWidth()
		&& a.getHeight() == b.getHeight();		
	if (sameSize) {
		int height = a.getHeight();
		int width = a.getWidth();				
		ImageDataStructure aDataStructure = a.m_imageDataStructure;
		ImageDataStructure bDataStructure = a.m_imageDataStructure;
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				
				if (aDataStructure.getPixel(i, j) != bDataStructure.getPixel(i, j)) {
					return false;
				}
			}
		}
		return true;
	}
	return false;
}
bool operator!=(const Image& a, const Image& b) {
	bool sameSize = a.getWidth() == b.getWidth()
		&& a.getHeight() == b.getHeight();
	if (sameSize) {
		int height = a.getHeight();
		int width = a.getWidth();
		ImageDataStructure aDataStructure = a.m_imageDataStructure;
		ImageDataStructure bDataStructure = a.m_imageDataStructure;
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{

				if (aDataStructure.getPixel(i, j) != bDataStructure.getPixel(i, j)) {
					return true;
				}
			}
		}
		return false;
	}
	return true;
}

Image operator+(const Image& a, const Image& b)
{
	int newHeight = std::max(a.getHeight(), b.getHeight());
	int newWidth = a.getWidth() + b.getWidth();
	
	ImageDataStructure newImageDataStructure = ImageDataStructure(newHeight,newWidth);
	// paint first image:
	for (int i = 0; i < a.getHeight(); i++)
	{
		for (int j = 0; j < a.getWidth(); j++)
		{
			Pixel pixel = a.m_imageDataStructure.getPixel(i, j);
			newImageDataStructure.paintPixel(i, j, pixel);
		}
	}
	// paint second image:
	for (int i = a.getHeight(); i < newHeight; i++)
	{
		for (int j = newWidth; j < newWidth; j++)
		{
			Pixel pixel = a.m_imageDataStructure.getPixel(i, j);
			newImageDataStructure.paintPixel(i, j, pixel);
		}
	}
	Image newImage = Image(newHeight, newWidth);
	newImage.m_imageDataStructure = newImageDataStructure;
	return newImage;
}

Image operator+=(Image& a, const Image& b)
{
	Image temp = (a + b);
	a = temp;
	return a;
}

std::ostream& operator<<(std::ostream& os, const Image& a)
{	
	for (int i = 0; i < a.getHeight(); i++)
	{
		for (int j = 0; j < a.getWidth(); j++)
		{
			os << a.m_imageDataStructure.getPixel(i, j);
		}
		os << std::endl;
	}
	return os;
}

Image operator|(const Image& a, const Image& b)
{
	int newHeight = std::max(a.getHeight(), b.getHeight());
	int newWidth = std::max(a.getWidth(), b.getWidth());
	ImageDataStructure newImageDataStructure = ImageDataStructure(newHeight, newWidth);
	for (int i = 0; i < newHeight; i++)
	{
		for (int j = 0; j < newWidth; j++)
		{
			if (i < a.getHeight() && i < b.getHeight() && j < a.getWidth() && j < b.getWidth()) {
				Pixel pixelToPaint = a.m_imageDataStructure.getPixel(i, j) | b.m_imageDataStructure.getPixel(i, j);
				newImageDataStructure.paintPixel(i, j, pixelToPaint);
			}
			else {				
				newImageDataStructure.paintPixel(i, j, Pixel());
			}
		}
	}
	Image newImage(newHeight, newWidth);
	newImage.m_imageDataStructure = newImageDataStructure;
	return newImage;
}

Image operator|=(Image& a, const Image& b)
{
	Image newImage = a | b;
	a = newImage;
	return newImage;
}

Image operator&(const Image& a, const Image& b)
{
	int newHeight = std::min(a.getHeight(), b.getHeight());
	int newWidth = std::min(a.getWidth(), b.getWidth());
	ImageDataStructure newImageDataStructure = ImageDataStructure(newHeight, newWidth);
	for (int i = 0; i < newHeight; i++)
	{
		for (size_t j = 0; j < newWidth; j++)
		{
			Pixel pixel = a.m_imageDataStructure.getPixel(i, j) & b.m_imageDataStructure.getPixel(i, j);
			newImageDataStructure.paintPixel(i, j, pixel);
		}
	}
	Image newImage = Image(newHeight, newWidth);
	newImage.m_imageDataStructure = newImageDataStructure;
	return newImage;
}

Image operator&=(Image& a, const Image& b)
{
	Image tempImage = a & b;
	a = tempImage;
	return tempImage;
}

Image operator*(const Image& a, unsigned int n)
{
	Image finalImage = Image(a.getHeight()*n, a.getWidth()*n);
	
	for (int i = 0; i < n; i++)
	{
		Image tempImage = Image(a.getHeight(), a.getWidth());
		ImageDataStructure newImageDataStructure = ImageDataStructure(a.getHeight(), a.getWidth());
		newImageDataStructure.paintAll(a.m_imageDataStructure);
		tempImage.m_imageDataStructure = newImageDataStructure;
		finalImage += tempImage;
	}
	return finalImage;
}

Image operator*(unsigned int n, const Image& a)
{	
	return a * n;
}

Image operator*=(Image& a, unsigned int n)
{
	Image tempImage = n * a;
	a = tempImage;
	return tempImage;
}

Image operator~(const Image& a)
{
	Image temp(a);
	for (int rowIndex = 0; rowIndex < a.getHeight(); rowIndex++)
	{
		for (int colIndex = 0 ; colIndex < a.getWidth(); colIndex++)
		{
			Pixel tempPixel = a.m_imageDataStructure.getPixel(rowIndex, colIndex);
			temp.m_imageDataStructure.paintPixel(rowIndex, colIndex, ~tempPixel);	
		}
	}
	return temp;
}

