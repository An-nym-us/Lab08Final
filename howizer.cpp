#include "howitzer.h"



Howitzer::Howitzer(Position ptUpperRight) :ptUpperRight(ptUpperRight), ground(ptUpperRight)
{

    ptHowitzer.setPixelsX(Position(ptUpperRight).getPixelsX() / randomDoubleInRange());
    ptHowitzer.setPixelsY(Position(ptUpperRight).getPixelsY() / randomDoubleInRange());
    ground.reset(ptHowitzer);
    launchAngle = 0;
    muzzleVelocity = 827;

}



double Howitzer::randomDoubleInRange()
{
    return (rand() % 2) + 1.7;
}


