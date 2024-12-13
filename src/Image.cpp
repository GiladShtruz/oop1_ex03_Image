#include "Image.h"

Image::Image():mImage(){}

Image::Image(int height, int width)
	:mImage(height,width)
{}

Image::Image(int height, int width, Pixel pixel)
:mImage(height,width,pixel)
{}
