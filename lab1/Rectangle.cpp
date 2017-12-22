#include "Rectangle.h"
#include <iostream>
#include <cmath>

Rectangle::Rectangle() : Rectangle(0, 0)
{
}

Rectangle::Rectangle(size_t i, size_t j) : side_a(i), side_b(j)
{
	std::cout << "Rectangle created: " << std::endl;
	std::cout << "side a = " << side_a << std::endl;
	std::cout << "side b = " << side_b << std::endl;
	
}

Rectangle::Rectangle(std::istream &is)
{
	std::cout << "Enter side a: ";
	is >> side_a;
	std::cout << "Enter side b: ";
	is >> side_b;
	
}

Rectangle::Rectangle(const Rectangle& orig) {
	std::cout << "Rectangle copy created" << std::endl;
	side_a = orig.side_a;
	side_b = orig.side_b;
	
}

double Rectangle::Square()
{
	return double(side_a) * double(side_b) ;
}

void Rectangle::Print() 
{
	std::cout << "Figure type - Rectangle " << std::endl;
	std::cout << "Size of side a: " << side_a << std::endl;
	std::cout << "Size of side b: " << side_b << std::endl;
	
}

Rectangle::~Rectangle()
{
	std::cout << "Rectangle deleted" << std::endl;
}
