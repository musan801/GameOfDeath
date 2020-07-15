#include "Human.h"

Human::Human()
{
    string Name;
    ImmunityLevel=(rand()%(100))/100; // initial immunity is Random
    CurrentPos=Point(0,0);
    InitialPos = Point(0, 0);
    if ((rand() % (100)) < 30)   // 30% of the people will have the virus
        HasVirus = 0;
    else
        HasVirus = 1;
    isHome = false;

}



void Human::setInitialPos(int x,int y)
{
    InitialPos.setX(x);
    InitialPos.setY(y);
}


string Human::getName() const
{
    return Name;
}

void Human::setName(string Name)
{
    this->Name = Name;
}

float Human::getImmunityLevel() const
{
    return ImmunityLevel;
}

void Human::setImmunityLevel(float ImmunityLevel)
{
    this->ImmunityLevel = ImmunityLevel;
}

Point Human::getCurrentPos() const
{
    return CurrentPos;
}

void Human::setCurrentPos(Point CurrentPos)
{
    this->CurrentPos = CurrentPos;
}

Point Human::getInitialPos() const
{
    return InitialPos;
}

void Human::setInitialPos(Point InitialPos)
{
    this->InitialPos = InitialPos;
}

bool Human::getHasVirus() const
{
    return HasVirus;
}

void Human::setHasVirus(bool HasVirus)
{
    this->HasVirus = HasVirus;
}

bool Human::getIsHome() const
{
    return isHome;
}

void Human::setIsHome(bool isHome)
{
    this->isHome = isHome;
}

