#pragma once
#include <iosfwd>

const unsigned char BLACK = (unsigned char)219;
const unsigned char GRAY = (unsigned char)176;
const unsigned char WHITE = ' ';

class Pixel {
public:
	Pixel(unsigned char color = ' ');
	unsigned char getColor()const;
	void setPixel(unsigned char color);
	//Pixel operator=(const Pixel& b);
private:
	bool validColor(unsigned int color);
	unsigned char m_color = WHITE;

};
bool operator==(const Pixel& a, const Pixel& b);
bool operator!=(const Pixel& a, const Pixel& b);
Pixel operator&(const Pixel& a, const Pixel& b);
Pixel& operator&=(Pixel& a, const Pixel& b);
Pixel operator|(const Pixel& a, const Pixel& b);
Pixel& operator|=(Pixel& a, const Pixel& b);
Pixel operator~(const Pixel& a);
std::ostream& operator<<(std::ostream& os, const Pixel& a);