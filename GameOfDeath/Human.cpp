#include "Human.h"

bool Human::isInContact()
{
    return false;
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
