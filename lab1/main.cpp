#include <cstdlib>
#include "Trapeze.h"
#include "Rhomb.h"
#include "Rectangle.h"


int main(int argc, char** argv)
{

	size_t num;
	while (true)
	{
		std::cout << "Menu" << std::endl;
		std::cout << "1) Trapeze" << std::endl;
		std::cout << "2) Rhomb" << std::endl;
		std::cout << "3) Rectangle" << std::endl;
		std::cout << "4) Exit" << std::endl;

		std::cout << "Choose action: ";
		std::cin >> num;

		if (num == 4)
			break;

		if (num > 4)
		{
			std::cout << "Error. No such action in menu" << std::endl;

			continue;
		}

		switch (num)
		{
		case 1:
		{

			Figure *ptr = new Trapeze(std::cin);
			ptr->Print();
			std::cout << ptr->Square() << std::endl;

			delete ptr;
			break;
		}

		case 2:
		{

			Figure *ptr = new Rhomb(std::cin);
			ptr->Print();
			std::cout << ptr->Square() << std::endl;

			delete ptr;
			break;
		}

		case 3:
		{

			Figure *ptr = new Rectangle(std::cin);
			ptr->Print();
			std::cout << ptr->Square() << std::endl;

			delete ptr;
			break;
		}

		}
		
	}
	return 0;
}
