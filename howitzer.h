#pragma once

#include "position.h"
#include "uiDraw.h"
#include "ground.h"
#include <iostream>
using namespace std;

class Howitzer
{
public:

    Howitzer(Position ptUpperRight);

    Ground getGround() { return ground; }



    // Get the Position of the Howitzer
    Position getptHowitzer() { return ptHowitzer; }
    double getLaunchAngle() { return launchAngle; }
    double getMuzzleVelocity() { return muzzleVelocity; }



    double randomDoubleInRange();
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
