#include "Rhomb.h"
#include <iostream>
#include <cmath>

Rhomb::Rhomb() : Rhomb(0, 0)
{
}

Rhomb::Rhomb(size_t i, size_t j) : side_a(i), height_h(j)
{
	std::cout << "Rhomb created: " << std::endl;
	std::cout << "side a = " << side_a << std::endl;
	std::cout << "height_h = " << height_h << std::endl;
}

Rhomb::Rhomb(std::istream &is)
{
	std::cout << "Enter side a: ";
	is >> side_a;
	std::cout << "Enter height h: ";
	is >> height_h;
}

Rhomb::Rhomb(const Rhomb& orig) {
	std::cout << "Rhomb copy created" << std::endl;
	side_a = orig.side_a;
	height_h = orig.height_h;
}

double Rhomb::Square()
{
	return double(side_a) * double(height_h);
}

void Rhomb::Print()
{
	std::cout << "Figure type - rhomb " << std::endl;
	std::cout << "Size of side a: " << side_a << std::endl;
	std::cout << "Height: " << height_h << std::endl;
}

Rhomb::~Rhomb()
{
	std::cout << "Rhomb deleted" << std::endl;
}