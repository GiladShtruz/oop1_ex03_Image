#include "Image.h"
#include "Pixel.h"
#include "ImageDataStructure.h"
#include "iostream"

Image::Image() 
	:m_height(0), m_width(0),
	m_imageDataStructure(ImageDataStructure())
{}

Image::Image(int height, int width)
	:m_height(height), m_width(width),
	m_imageDataStructure(ImageDataStructure(height, width))
{}

Image::Image(int height, int width, Pixel pixel)
	:m_height(height), m_width(width), 
	m_imageDataStructure(ImageDataStructure(height, width))
{
	paint(pixel);
}

unsigned int Image::GetWidth() const {
	return m_width;
}

unsigned int Image::GetHeight() const
{
	return m_height;
}
//this operator return by reference (x,y) pixel
Pixel& Image::operator()(unsigned int x, unsigned int y)
{
		return m_imageDataStructure.mPixels[x][y];
}

Image& Image::operator=(const Image& other)
{
	m_height = other.GetHeight();
	m_width = other.GetWidth();
	if (this != &other)
	{
		m_imageDataStructure = other.m_imageDataStructure;
		return *this;
	}
	return *this;
}


const Pixel& Image::operator()(unsigned int x, unsigned int y) const
{
		return m_imageDataStructure.mPixels[x][y];
}


void Image::paint(Pixel pixel)
{
	for (int rowIndex = 0; rowIndex < m_height; rowIndex++)
	{
		for (int colIndex = 0; colIndex < m_width; colIndex++)
		{
			//(rowIndex, colIndex) = pixel.getColor();
			m_imageDataStructure.mPixels[rowIndex][colIndex].setPixel(pixel.getColor());// = pixel.getColor();
		}
	}
}


bool operator==(const Image& a, const Image& b) {
	bool sameSize = a.GetWidth() == b.GetWidth()
		&& a.GetHeight() == b.GetHeight();		
	if (sameSize) {
		int height = a.GetHeight();
		int width = a.GetWidth();				
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				
				if (a(i, j) != b(i, j)) {
					return false;
				}
			}
		}
		return true;
	}
	return false;
}
bool operator!=(const Image& a, const Image& b) {
	if (a == b)
		return false;
	return true;
}

Image operator+(const Image& a, const Image& b)
{
	if (a.GetHeight() == 0 || a.GetWidth() == 0) return b;
	if (b.GetHeight() == 0 || b.GetWidth() == 0) return a;
	int newHeight = std::max(a.GetHeight(), b.GetHeight());
	int newWidth = a.GetWidth() + b.GetWidth();
	Image newImage(newHeight, newWidth);
	//paint first image
	for (int rowIndex = 0; rowIndex < a.GetHeight(); rowIndex++)
	{
		for (int colIndex = 0; colIndex < a.GetWidth(); colIndex++)
		{
			newImage(rowIndex, colIndex) = a(rowIndex, colIndex);
		}
	}	
	//paint seconed image
	for (int rowIndex = 0; rowIndex < b.GetHeight(); rowIndex++)
	{
		for (int colIndex = 0; colIndex < b.GetWidth(); colIndex++)
		{
			
			newImage(rowIndex, colIndex+ a.GetWidth()) = b(rowIndex, colIndex);
		}
	}
	return newImage;
}
/*
Image operator+(const Image& a, const Image& b)
{
	int newHeight = std::max(a.GetHeight(), b.GetHeight());
	int newWidth = a.GetWidth() + b.GetWidth();
	
	ImageDataStructure newImageDataStructure = ImageDataStructure(newHeight,newWidth);
	// paint first image:
	for (int i = 0; i < a.GetHeight(); i++)
	{
		for (int j = 0; j < a.GetWidth(); j++)
		{
			Pixel pixel = a.m_imageDataStructure.getPixel(i, j);
			newImageDataStructure.paintPixel(i, j, pixel);
		}
	}
	// paint second image:
	for (int i = a.GetHeight(); i < newHeight; i++)
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
*/
Image operator+=(Image& a, const Image& b)
{
	a = a+b;
	return a;
}

std::ostream& operator<<(std::ostream& os, const Image& a)
{	
	for (int i = 0; i < a.GetHeight(); i++)
	{
		for (int j = 0; j < a.GetWidth(); j++)
		{
			os << a(i,j);
		}
		os << std::endl;
	}
	return os;
}
Image operator|(const Image& a, const Image& b)
{
	int newHeight = std::max(a.GetHeight(), b.GetHeight());
	int newWidth = std::max(a.GetWidth(), b.GetWidth());
	Image newImage(newHeight, newWidth, Pixel(WHITE));
	for (int rowIndex = 0; rowIndex < a.GetHeight(); rowIndex++)
	{
		for (int colIndex = 0; colIndex < a.GetWidth(); colIndex++)
		{
			newImage(rowIndex, colIndex) = a(rowIndex, colIndex) | newImage(rowIndex,colIndex);
		}
	}
	for (int rowIndex = 0; rowIndex < b.GetHeight(); rowIndex++)
	{
		for (int colIndex = 0; colIndex < b.GetWidth(); colIndex++)
		{
			newImage(rowIndex, colIndex) = b(rowIndex, colIndex) | newImage(rowIndex,colIndex);
		}
	}
	return newImage;
}

Image operator|=(Image& a, const Image& b)
{
	Image temp = a | b;
	a = temp;
	return a ;
}
Image operator&(const Image& a, const Image& b)
{
	int newHeight = std::min(a.GetHeight(), b.GetHeight());
	int newWidth = std::min(a.GetWidth(), b.GetWidth());
	Image newImage(newHeight, newWidth, Pixel(WHITE));
	for (int rowIndex = 0; rowIndex < newHeight; rowIndex++)
	{
		for (int colIndex = 0; colIndex < newWidth; colIndex++)
		{
			newImage(rowIndex, colIndex) = a(rowIndex, colIndex) & b(rowIndex, colIndex);
		}
	}
	return newImage;
}

Image operator&=(Image& a, const Image& b)
{
	a = a & b;
	return a;
}
Image operator*(const Image& a, unsigned int n)
{
	
	Image finalImage = a;
	//if (n == 1) return finalImage;
	for (int i = 1; i < n; i++)
	{
		finalImage += a;
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
	Image temp = a;
	for (int rowIndex = 0; rowIndex < a.GetHeight(); rowIndex++)
	{
		for (int colIndex = 0 ; colIndex < a.GetWidth(); colIndex++)
		{
			temp(rowIndex,colIndex) = ~a(rowIndex, colIndex);
		}
	}
	return temp;
}
/*
Image operator&(const Image& a, const Image& b)
{
	int newHeight = std::min(a.GetHeight(), b.GetHeight());
	int newWidth = std::min(a.GetWidth(), b.GetWidth());
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

*/
/*

Image operator|(const Image& a, const Image& b)
{
	int newHeight = std::max(a.GetHeight(), b.GetHeight());
	int newWidth = std::max(a.GetWidth(), b.GetWidth());
	ImageDataStructure newImageDataStructure = ImageDataStructure(newHeight, newWidth);
	for (int i = 0; i < newHeight; i++)
	{
		for (int j = 0; j < newWidth; j++)
		{
			if (i < a.GetHeight() && i < b.GetHeight() && j < a.GetWidth() && j < b.GetWidth()) {
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
*/