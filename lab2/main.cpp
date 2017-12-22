#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include "TList.h"
#include "rectangle.h"
#include "TListItem.h"



int main() {
	setlocale(LC_ALL, "Russian");
	int a;
	TList list;
	Rectangle rec;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "-------------------МЕНЮ-------------------" << std::endl;
	std::cout << "|1-Добавить фигуру                       |" << std::endl;
	std::cout << "|2-Удалить фигуру                        |" << std::endl;
	std::cout << "|3-Расспечатать список                   |" << std::endl;
	std::cout << "|4-Выход                                 |" << std::endl;
	do {
		std::cout << "Выберете действие:" << std::endl;
		if (!(std::cin >> a)) {
			std::cin.clear();
			while (std::cin.get() != '\n');
		}
		switch (a) {
		case 1: {
			std::cin >> rec;
			list.Insert(rec);
			break;
		}
		case 2: {
			rec = list.Delete();
			break;
		}
		case 3: {
			std::cout << list;
			break;
		}
		case 4: {
			break;
		}
		default: std::cout << "Неверный ввод. Попробуйте снова" << std::endl;
			break;
		}
	} while (a != 4);
	return 0;
}