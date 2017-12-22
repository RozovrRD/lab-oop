#include <iostream>
#include <cmath>
#include <algorithm>
#include "rectangle.h"


Rectangle::Rectangle() : Rectangle(0, 0)
{
}

Rectangle::Rectangle(int32_t side_a, int32_t side_b): side_a(side_a), side_b(side_b)
{
   
}

Rectangle::Rectangle(std::istream &is)
{
    is >> side_a;
    is >> side_b;
    
    if(side_a < 0 || side_b < 0 ) {
        std::cerr << "Error: sides should be > 0." << std::endl;
    }
}

Rectangle::Rectangle(const Rectangle &orig)
{
    side_a = orig.side_a;
    side_b = orig.side_b;
    }

double Rectangle::Square()
{
    
    return (side_a*side_b);
}

void Rectangle::Print()
{
    std::cout << "side_a base = " << side_a << ", side_b base = " << side_b << std::endl;
}

Rectangle::~Rectangle()
{
}

std::ostream& operator <<(std::ostream &os, const Rectangle &obj)
{
    os << obj.side_a << " " << obj.side_b;
    return os;
}

std::istream& operator >>(std::istream &is, Rectangle &obj)
{
    std::cout << "Enter side_a base: ";
    is >> obj.side_a;
    std::cout << "Enter side_b base: ";
    is >> obj.side_b;
      
    return is;
}

bool Rectangle::operator ==(const Rectangle &obj) const
{
    return side_a == obj.side_a && side_b == obj.side_b ;
}


Rectangle& Rectangle::operator =(const Rectangle &obj)
{
    if (&obj == this) {
        return *this;
    }

    side_a = obj.side_a;
    side_b = obj.side_b;
    
    return *this;
}


