#include "stdafx.h"
#include "Rhombus.h"

Rhombus::Rhombus() {
	side = 0.0;
	height = 0.0;
}
Rhombus::Rhombus(std::istream& is) {
	std::cout << "Введите сторону: " << std::endl;
	if (!(is >> side)) {
		is.clear();
		while (is.get() != '\n');
		err = true;
		return;
	}
	std::cout << "Введите высоту: " << std::endl;
	if (!(is >> height)) {
		is.clear();
		while (is.get() != '\n');
		err = true;
		return;
	}
	if (height>side) {
		err = true;
		return;
	}
}
void Rhombus::Print() {
	std::cout << "Тип фигуры: ромб" << std::endl;
	std::cout << "Сторона= " << side << std::endl;
	std::cout << "Высота= " << height << std::endl;
}
double Rhombus::Square() {
	return side*height;
}