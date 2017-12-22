#pragma once
#ifndef Rhomb_H
#define Rhomb_H

#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Rhomb : public Figure
{
public:
	Rhomb();
	Rhomb(std::istream &is);
	Rhomb(size_t i, size_t j);
	Rhomb(const Rhomb& orig);

	double Square() override;
	void Print() override;
	virtual ~Rhomb();

private:
	size_t side_a;
	size_t height_h;
};

#endif