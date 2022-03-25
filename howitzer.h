#pragma once

#include "position.h"
#include "uiDraw.h"
#include "ground.h"
#include <iostream>
using namespace std;

class Howitzer
{
public:

    //Howitzer(Position ptUpperRight);

    /*Howitzer(Position ptUpperRight);*/
    Howitzer(Position ptUpperRight) :ptUpperRight(ptUpperRight) , ground(ptUpperRight)
    {

        ptHowitzer.setPixelsX(Position(ptUpperRight).getPixelsX() / 2.0);
        ptHowitzer.setPixelsY(Position(ptUpperRight).getPixelsY() / 4.0);
        cout << ptHowitzer.getPixelsY() << endl;
        ground.reset(ptHowitzer);
        launchAngle = 0;
        muzzleVelocity = 0;
    }





    Position getptHowitzer() { return ptHowitzer; }
    Ground getGround() { return ground; }



    // Get the Position of the Howitzer
    double getLaunchAngle() { return launchAngle; }
    void advanceLaunchAngleFullStep() { launchAngle += 0.03; }
    void decrementLaunchAngleFullStep() { launchAngle -= 0.03; }    // angle of the howitzer };
    void advanceLaunchAngleHalfStep() { launchAngle += launchAngle >= 0 ? -0.002 : 0.002; }
    void decrementLaunchAngleHalfStep() { launchAngle += launchAngle >= 0 ? 0.002 : -0.002; }




private:

    double launchAngle;
    Ground ground;
    Position  ptHowitzer;          // location of the howitzer
    Position ptUpperRight;
    double muzzleVelocity;
};
