#include <functional>
#include <random>
#include <chrono>
#include <string>
#include <mutex>
#include <thread>
#include "queue.h"
#include "rhomb.h"
#include "rectangle.h"
#include "trapezoid.h"

typedef std::function<void(void)> Command;

int main()
{
	Queue<Figure> q;
	List<Command> cmds;
	List<std::string> cmdsNames;
	std::mutex mtx;

	Command cmdInsert = [&]()
	{
		std::lock_guard<std::mutex> guard(mtx);

		unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();

		std::default_random_engine generator(seed);
		std::uniform_int_distribution<int> distrFigureType(1, 3);
		std::uniform_int_distribution<int> distrFigureParam(1, 10);

		std::cout << "================" << std::endl;
		std::cout << "Command: insert" << std::endl;

		switch (distrFigureType(generator))
		{
		case 1:
		{
			std::cout << "================" << std::endl;
			std::cout << "Inserted: square" << std::endl;

			double side_1 = distrFigureParam(generator);
			double height = distrFigureParam(generator);

			q.push(std::shared_ptr<Rhomb>(new Rhomb(side_1,height)));

			break;
		}

		case 2:
		{
			std::cout << "================" << std::endl;
			std::cout << "Inserted: rectangle" << std::endl;

			double sideA = distrFigureParam(generator);
			double sideB = distrFigureParam(generator);

			q.push(std::shared_ptr<Rectangle>(new Rectangle(sideA, sideB)));

			break;
		}

		case 3:
		{
			std::cout << "================" << std::endl;
			std::cout << "Inserted: trapezoid" << std::endl;

			double sideA = distrFigureParam(generator);
			double sideB = distrFigureParam(generator);
			double height = distrFigureParam(generator);

			q.push(std::shared_ptr<Trapezoid>(new Trapezoid(sideA, sideB, height)));

			break;
		}
		}
	};

	Command cmdErase = [&]()
	{
		std::lock_guard<std::mutex> guard(mtx);

		const double AREA = 24.0;

		std::cout << "================" << std::endl;
		std::cout << "Command: erase" << std::endl;

		if (q.size() == 0)
		{
			std::cout << "================" << std::endl;
			std::cout << "Queue is empty" << std::endl;
		}
		else
		{
			std::shared_ptr<Figure> first = q.front();

			while (true)
			{
				bool isRemoved = false;

				for (auto figure : q)
				{
					if (figure->area() < AREA)
					{
						std::cout << "================" << std::endl;
						std::cout << "Removed" << std::endl;

						figure->print();
						std::cout << "Area: " << figure->area() << std::endl;

						q.pop();
						isRemoved = true;

						break;
					}
				}

				if (!isRemoved)
					break;
			}
		}
	};
