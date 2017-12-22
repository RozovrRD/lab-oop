#include <cstdlib>
#include <iostream>
#include "TList.h"

int main()
{
    int act = 0;
    TList list;
    Rectangle rectangle;
    std::cout << "Choose an operation:" << std::endl;
    std::cout << "1) Add rectangle" << std::endl;
    std::cout << "2) Delete rectangle from list" << std::endl;
    std::cout << "3) Print list"  << std::endl;
    std::cout << "0) Exit" << std::endl;
    while (std::cin >> act && act) {
        switch(act) {
        case 1:
            std::cin >> rectangle;
            list.Push(rectangle);
            break;
        case 2:
            rectangle = list.Pop();
            break;
        case 3:
            std::cout << list << std::endl;
            break;
        default:
            std::cout << "Incorrect command" << std::endl;;
            break;
        }
        std::cout << "Choose an operation:" << std::endl;
        std::cout << "1) Add rectangle" << std::endl;
        std::cout << "2) Delete rectangle from list"  << std::endl;
        std::cout << "3) Print list"  << std::endl;
        std::cout << "0) Exit" << std::endl;
    }
    return 0;
}
