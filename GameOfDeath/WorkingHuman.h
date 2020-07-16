#pragma once
#include "Human.h"
#include "Office.h"
class WorkingHuman :
    public Human
{
    Office* MyOffice;// when init 

public:
    WorkingHuman() {}
    WorkingHuman(Office* o,Point p ) {
        MyOffice = o;
        InitialPos = p;
        CurrentPos = p;
        ImmunityLevel = (rand() % (100)) / 100;
        isHome = true;
        if ((rand() % (100)) < 30)   // 30% of the working people will have the virus
            HasVirus = 0;
        else
            HasVirus = 1;
    }
    Office* getMyOffice() const;
    void setMyOffice(Office* MyOffice);
    Point GoToPos();
    Point getInitialPos() {
        return InitialPos;
    }

};
