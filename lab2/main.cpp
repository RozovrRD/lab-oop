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
	std::cout << "-------------------����-------------------" << std::endl;
	std::cout << "|1-�������� ������                       |" << std::endl;
	std::cout << "|2-������� ������                        |" << std::endl;
	std::cout << "|3-������������ ������                   |" << std::endl;
	std::cout << "|4-�����                                 |" << std::endl;
	do {
		std::cout << "�������� ��������:" << std::endl;
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
		default: std::cout << "�������� ����. ���������� �����" << std::endl;
			break;
		}
	} while (a != 4);
	return 0;
}