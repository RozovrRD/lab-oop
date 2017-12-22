#ifndef TRAPEZIUM_H
#define TRAPEZIUM_H

#include <iostream>
#include "Figure.h"

class Trapezium : public Figure {
public:
	Trapezium();
	Trapezium(std::istream& is);

	void Print() override;
	double Square() override;

private:
	double side_a;
	double side_b;
	double height;
};

#endif
