#ifndef RHOMB_H
#define RHOMB_H

#include <iostream>
#include "figure.h"

class Rhomb : public Figure
{
public:
	Rhomb();
	Rhomb(std::istream& is);

	void print() const override;
	double area() const override;
	const char* getName() const override;

	Rhomb& operator = (const Rhomb& other);
	bool operator == (const Rhomb& other) const;

	void* operator new (unsigned int size);
	void operator delete (void* p);

	friend std::ostream& operator << (std::ostream& os, const Rhomb& rectangle);
	friend std::istream& operator >> (std::istream& is, Rhomb& rectangle);

private:
	double m_sideA;
	double small_ang;
};

#endif