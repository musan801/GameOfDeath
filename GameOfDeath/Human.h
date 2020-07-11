#pragma once
#include "Point.h"
#include <string>
using namespace std;
class Human
{
    string Name;
    float ImmunityLevel;
    Point CurrentPos;
    Point InitialPos;
    bool isInContact(); //Funtion for checking if Human is in contact with any other human

public:
    string getName() const;
    void setName(string Name);

    float getImmunityLevel() const;
    void setImmunityLevel(float ImmunityLevel);

    Point getCurrentPos() const;
    void setCurrentPos(Point CurrentPos);

    Point getInitialPos() const;
    void setInitialPos(Point InitialPos);

};
