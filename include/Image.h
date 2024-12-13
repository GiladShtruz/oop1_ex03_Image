#pragma once
#include "ImageDataStructure.h"
#include "Pixel.h"
class Image
{
public:
	Image();
	Image(int height, int width);
	Image(int height, int width, Pixel pixel);
	void operator+=(const Image& other);
private:
	ImageDataStructure mImage;
};

bool operator==(const Image& a, const Image& b);
bool operator!=(const Image& a, const Image& b);
Image operator+(const Image& a, const Image& b);
Image operator|(const Image& a, const Image& b);
Image operator|=(const Image& a, const Image& b);
Image operator&(const Image& a, const Image& b);
Image operator&=(const Image& a, const Image& b);
std::ostream& operator<<(std::ostream& os, const Image& a);