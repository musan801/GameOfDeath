#pragma once
#include <string>
#include "Point.h"

using namespace std;

class Office
{
    string Name; //Name of the office
    Point Pos; //Current  location in the habitat

public:
    Office();
    string getName() const;
    void setName(string Name);

    Point getPos() const;
    void setPos(Point Pos);

};
