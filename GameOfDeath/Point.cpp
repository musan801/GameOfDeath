#include "Point.h"


Point::Point()
{
    X = 0;
    Y = 0;
}

Point::Point(const Point& p2)
{
    X = p2.X;
    Y = p2.Y;
    
}

Point::Point(int a, int b) {
    X = a;
    Y = b;
}

int Point::getX() 
{
    return X;
}

void Point::setX(int X)
{
    this->X = X;
}

int Point::getY() 
{
    return Y;
}

void Point::setY(int Y)
{
    this->Y = Y;
}
