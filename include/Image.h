#pragma once
#include "ImageDataStructure.h"
#include "Pixel.h"
class Image
{ 
public:
	Image();
	Image(int height, int width);
	Image(int height, int width, Pixel pixel);
	unsigned int getWidth() const;
	unsigned int getHeight() const;
	ImageDataStructure m_imageDataStructure;
	
	
private:
	unsigned int m_height;
	unsigned int m_width;
	
	
};

bool operator==(const Image& a, const Image& b);
bool operator!=(const Image& a, const Image& b);
Image operator+(const Image& a, const Image& b);
Image operator+=(Image& a, const Image& b);

std::ostream& operator<<(std::ostream& os, const Image& a);
Image operator|(const Image& a, const Image& b);
Image operator|=(Image& a, const Image& b);
Image operator&(const Image& a, const Image& b);
Image operator&=(Image& a, const Image& b);
Image operator*(const Image& a, unsigned int n);
Image operator*(unsigned int n,const Image& a);
Image operator*=(Image& a, unsigned int n);
Image operator~(const Image& a);

// void operator+=(const Image& other);