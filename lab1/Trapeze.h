#pragma once
#ifndef Trapeze_H
#define Trapeze_H

#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Trapeze : public Figure
{
public:
	Trapeze();
	Trapeze(std::istream &is);
	Trapeze(size_t i, size_t j, size_t k);
	Trapeze(const Trapeze& orig);

	double Square() override;
	void Print() override;
	virtual ~Trapeze();

private:
	size_t side_a;
	size_t side_b;
	size_t height_h;
};

#endif