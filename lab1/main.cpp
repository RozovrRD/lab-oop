#include "stdafx.h"
#include <iostream>
#include <clocale>
#include "Rectangle.h"
#include "Trapezium.h"
#include "Rhombus.h"

void test(Figure* figure) {
	if (figure->err) {
		std::cout << "Некорректные входные данные" << std::endl;
		return;
	}
	figure->Print();
	std::cout << "Площадь фигуры= " << figure->Square() << std::endl;
	delete figure;
}

int main()
{
	setlocale(LC_CTYPE, "rus");
	int a;
	do {
		std::cout << "1) Прямоугольник\n" << "2) Трапеция\n" << "3) Ромб\n" << "4) Выход\n" << "Выберете действие: " << std::endl;
		if (!(std::cin >> a)) {
			std::cin.clear();
			while (std::cin.get() != '\n');
		}
		switch (a) {
		case 1:
			test(new Rectangle(std::cin));
			break;
		case 2:
			test(new Trapezium(std::cin));
			break;
		case 3:
			test(new Rhombus(std::cin));
			break;
		case 4: break;
		default:
			std::cout << "Ошибка. Такого пункта меню не существует\n" << std::endl;
			break;
		}
	} while (a != 4);
	return 0;
}
