#ifndef RHOMBUS_H
#define RHOMBUS_H

#include <iostream>
#include "Figure.h"

class Rhombus : public Figure {
public:
	Rhombus();
	Rhombus(std::istream& is);

	void Print() override;
	double Square() override;

private:

	double side;
	double height;
};

#endif