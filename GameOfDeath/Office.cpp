#include "Office.h"


string Office::getName() const
{
    return Name;
}

void Office::setName(string Name)
{
    this->Name = Name;
}

Point Office::getPos() const
{
    return Pos;
}

void Office::setPos(Point Pos)
{
    this->Pos = Pos;
}
