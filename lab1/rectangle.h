#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "Figure.h"

class Rectangle : public Figure {
public:
	Rectangle();
	Rectangle(std::istream& is);

	void Print() override;
	double Square() override;

private:
	double side_a;
	double side_b;
};

#endif
