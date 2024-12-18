#include "Pixel.h"
#include <ostream>
#include <iostream>

Pixel::Pixel(unsigned char color)
{
	std::cout << color;
	m_color = color;
}


unsigned char Pixel::getColor() const
{
	return m_color;
}

void Pixel::setPixel(unsigned char color)
{
	if (validColor(color))
	{
		m_color = color;
	}
}

//Pixel Pixel::operator=(const Pixel& b)
//{
//	setPixel(b.getColor());
//	return *this;
//}

bool Pixel::validColor(unsigned int color)
{
	if (color == BLACK || color == WHITE || color == GRAY)
		return true;
	return false;
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

std::ostream& operator<<(std::ostream& os, const Pixel& a)
{
	os << a.getColor();
	return os;
}
