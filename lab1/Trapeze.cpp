#include "Trapeze.h"

#include <iostream>
#include <cmath>

Trapeze::Trapeze() : Trapeze(0, 0, 0)
{
}

Trapeze::Trapeze(size_t i, size_t j, size_t k) : side_a(i), side_b(j), height_h(k)
{
	std::cout << "Trapeze created: " << std::endl;
	std::cout << "side a = " << side_a << std::endl;
	std::cout << "side b = " << side_b << std::endl;
	std::cout << "height_h = " << height_h << std::endl;
}

Trapeze::Trapeze(std::istream &is)
{
	std::cout << "Enter side a: ";
	is >> side_a;
	std::cout << "Enter side b: ";
	is >> side_b;
	std::cout << "Enter height h: ";
	is >> height_h;
}

Trapeze::Trapeze(const Trapeze& orig) {
	std::cout << "Trapeze copy created" << std::endl;
	side_a = orig.side_a;
	side_b = orig.side_b;
	height_h = orig.height_h;
}

double Trapeze::Square()
{
	return double(side_a + side_b) * double(height_h) / 2.0;
}

void Trapeze::Print()
{
	std::cout << "Figure type - trapeze " << std::endl;
	std::cout << "Size of side a: " << side_a << std::endl;
	std::cout << "Size of side b: " << side_b << std::endl;
	std::cout << "Height: " << height_h << std::endl;
}

Trapeze::~Trapeze()
{
	std::cout << "Trapeze deleted" << std::endl;
}