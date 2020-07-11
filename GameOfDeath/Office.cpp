#include "Office.h"


Office::Office()
{
    Name = "Office";
    Pos.setX(0);
    Pos.setY(0);
}

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
