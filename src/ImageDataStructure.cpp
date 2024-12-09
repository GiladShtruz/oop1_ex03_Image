#include "ImageDataStructure.h"

ImageDataStructure::ImageDataStructure() :
	m_Height(0), m_Width(0), m_image(nullptr);

ImageDataStructure::ImageDataStructure(int height, int width)
	:ImageDataStructure(height, width, Pixel())
{
}
