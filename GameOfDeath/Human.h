#pragma once
#include "Point.h"
#include <string>
using namespace std;
class Human
{
protected:
    string Name;
    float ImmunityLevel;
    Point CurrentPos;
    Point InitialPos;
    bool HasVirus;
    bool isHome;

    

    

public:
    Human();
    bool isInContact(); //Funtion for checking if Human is in contact with any other human
    virtual Point GoToPos() {

        return CurrentPos;
    }

    void setInitialPos(int x, int y);

    string getName() const;
    void setName(string Name);

    float getImmunityLevel() const;
    void setImmunityLevel(float ImmunityLevel);

    Point getCurrentPos() const;
    void setCurrentPos(Point CurrentPos);

    Point getInitialPos() const;
    void setInitialPos(Point InitialPos);

    bool getHasVirus() const;
    void setHasVirus(bool HasVirus);

    bool getIsHome() const;
    void setIsHome(bool isHome);

};
