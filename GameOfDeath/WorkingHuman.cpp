#include "WorkingHuman.h"

Office* WorkingHuman::getMyOffice() const
{
    return MyOffice;
}

void WorkingHuman::setMyOffice(Office* MyOffice)
{
    this->MyOffice = MyOffice;
}

Point WorkingHuman::GoToPos() {

    if (isHome)
    {
        if (CurrentPos == MyOffice->getPos()) {
            isHome = false;
            return InitialPos;
        }
            return MyOffice->getPos();

    }
    else 
    {
        if (CurrentPos == InitialPos)
        {
            isHome = true;
            return MyOffice->getPos();
        }
            return InitialPos;
    }

}
