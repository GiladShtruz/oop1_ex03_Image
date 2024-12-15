#include "Pixel.h"
#include <ostream>

Pixel::Pixel(unsigned char color)
	:m_color(color){}


unsigned char Pixel::getColor() const
{
	return m_color;
}


bool operator==(const Pixel& a, const Pixel& b)
{
	
	return a.getColor() == b.getColor();
}

bool operator!=(const Pixel& a, const Pixel& b)
{
	return a.getColor() != b.getColor();
}

Pixel operator&(const Pixel& a, const Pixel& b)
{
	if (a.getColor()< b.getColor())
		return Pixel(a.getColor());
	return Pixel(b.getColor());
}

Pixel& operator&=(Pixel& a, const Pixel& b)
{
	auto temp = a & b;
	a = temp;
	return temp;
}


Pixel operator|(const Pixel& a, const Pixel& b)
{
	if (a.getColor() > b.getColor())
		return Pixel(a.getColor());
	return Pixel(b.getColor());
}

Pixel& operator|=(Pixel& a, const Pixel& b)
{
	auto temp = a | b;
	a = temp;
	return temp;
}


Pixel operator~(const Pixel& a)
{
	switch (a.getColor())
	{
	case BLACK:
		return Pixel(WHITE);
	case WHITE:
		return Pixel(BLACK);
	default:
	case GRAY:
		return Pixel(GRAY);
	}
}