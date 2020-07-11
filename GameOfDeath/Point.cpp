#include "Point.h"


Point::Point()
{
    X = 0;
    Y = 0;
}

Point::Point(int a, int b) {
    X = a;
    Y = b;
}

int Point::getX() const
{
    return X;
}

void Point::setX(int X)
{
    this->X = X;
}

int Point::getY() const
{
    return Y;
}

void Point::setY(int Y)
{
    this->Y = Y;
}
