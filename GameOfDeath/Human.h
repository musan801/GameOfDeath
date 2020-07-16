#pragma once
#include "Point.h"
#include <string>
using namespace std;
class Human
{
protected:
    string Name; //Name
    float ImmunityLevel;  //How immune a person is
    Point CurrentPos; // curent position
    Point InitialPos; // Initial position
    bool HasVirus; // if the person has the virus or not
    bool isHome; // if the person is home or not
    int RecoveryTime; // time needed to recover

public:

    int  getRecoveryTime() const;
    void setRecoveryTime(int t);
    Human();
   
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
