#pragma once
#include <iosfwd>

const unsigned char BLACK = (unsigned char)219;
const unsigned char GRAY = (unsigned char)176;
const unsigned char WHITE = ' ';

class Pixel {
public:
	Pixel(unsigned char pixel = ' ');

private:
	unsigned char m_color = WHITE;

};