#include "rhomb.h"
#include <cmath>
#define PI 3.1415
Rhomb::Rhomb()
{
	m_sideA = 0.0;
	small_ang = 0.0;
}

Rhomb::Rhomb(std::istream& is)
{
	is >> *this;
}

void Rhomb::print() const
{
	std::cout << *this;
}

double Rhomb::area() const
{
	return m_sideA * m_sideA * sin(small_ang * (PI/180));
}

const char* Rhomb::getName() const
{
	return "Rhomb";
}

Rhomb& Rhomb::operator = (const Rhomb& other)
{
	if (&other == this)
		return *this;

	m_sideA = other.m_sideA;
	small_ang = other.small_ang;

	return *this;
}

bool Rhomb::operator == (const Rhomb& other) const
{
	return m_sideA == other.m_sideA && small_ang == other.small_ang;
}

void* Rhomb::operator new (unsigned int size)
{
	return Figure::allocator.allocate();
}

void Rhomb::operator delete (void* p)
{
	Figure::allocator.deallocate(p);
}

std::ostream& operator << (std::ostream& os, const Rhomb& rectangle)
{
	os << "================" << std::endl;
	os << "Figure type: rhomb" << std::endl;
	os << "Side A size: " << rectangle.m_sideA << std::endl;
	os << "Smaller angle: " << rectangle.small_ang << std::endl;

	return os;
}

std::istream& operator >> (std::istream& is, Rhomb& rectangle)
{
	std::cout << "================" << std::endl;
	std::cout << "Enter side A: ";
	is >> rectangle.m_sideA;
	std::cout << "Enter smaller angle: ";
	is >> rectangle.small_ang;

	return is;
}
