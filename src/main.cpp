
#include <iostream>
#include "Pixel.h"
#include "Image.h"


int main()
{
	//Pixel p(176);
	//std::cout << i << std::endl;
	Pixel p1(GRAY);
	Pixel p2(BLACK);
	Image i(5, 3, p2);
	Image i1(3, 5, p1);
	Image i3 = (i1 + i);
	std::cout << i1<< std::endl<< std::endl;
	std::cout << i<< std::endl<< std::endl;
	std::cout << i3<< std::endl<< std::endl;
	//std::cout << i3<< std::endl;
	
	//i1 = i1 * 3;
	//std::cout << i1 << std::endl;
	//i = 2 * i;
	//std::cout << i << std::endl;
	//i *= 3;
	//std::cout << i << std::endl;
	//Image i2;
	//i2 = i | i1;
	//std::cout << i2 << std::endl;
	//i |= i2;
	//std::cout << i << std::endl;
	//Image i3;
	//i3 = ~i2;
	//std::cout << i3 << std::endl;
	return 0;
}