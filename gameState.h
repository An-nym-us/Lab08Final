#pragma once
#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "ground.h"     // for GROUND
#include "position.h"   // for POINT
#include <iostream>
#include <cmath>
#include "projectile.h"

class GameState
{
public:
    GameState(Position ptUpperRight) :
        ptUpperRight(ptUpperRight),
        ground(ptUpperRight),
        time(0.0),
        angle(0.0)
    {
        ptHowitzer.setPixelsX(Position(ptUpperRight).getPixelsX() / 2.0);
        ptHowitzer.setPixelsY(Position(ptUpperRight).getPixelsY() / 4.0);

        ground.reset(ptHowitzer);



        for (int i = 0; i < 20; i++)
        {
            {
                projectilePath[i].setPixelsX((double)i * 2.0);
                projectilePath[i].setPixelsY((double)i * 2.0);
                projectilePath[i].setPixelsY(ptUpperRight.getPixelsY() / 1.5);
            }
        }
    }
    // the ground



    double angle;
                   // amount of time since the last firing






    void GameStateTickProgress()
    {

        if (ground.hitTarget(this->getProjectile()->getCurrentPointLocation()))
        {
            cout << " YOU WIN!" << endl;
            return;
        }

        /* Check if the projecile is below the minimum elevationof the ground. if it is below the ground elevation then you loose*/
        if (ground.getElevationMeters(this->getProjectile()->getCurrentPointLocation()) > this->getProjectile()->getCurrentLocationY())
        {
            cout << "YOU LOSE  :(" << endl;
            return;
        }




        for (int i = 0; i < 20; i++)
        {
            double x = this->projectilePath->getPixelsX();
            double y = this->projectilePath->getPixelsY();
        }

        this->advanceTimer();
        this->getProjectile()->applyPhysics();


        this->projectilePath->setMetersY(this->getProjectile()->getCurrentLocationY());
        this->projectilePath->setMetersX(this->getProjectile()->getCurrentLocationX());
    };





    Position  projectilePath[20];  // path of the projectile

    Projectile* getProjectile() { return projectileInstance; }
    Ground getGround() { return ground; }
    Position getptHowitzer() { return ptHowitzer; }
    Position getptUpperRight() { return ptUpperRight; }


    void advanceTimer() { time += .5; }
    void resetTimer() { time = 0; }
    double getTimer() { return time; }



    /* No worky*/
    double getLaunchAngle() { return launchAngle; }
    void addLaunchAngle() { this->launchAngle += 0.05; }
    void subtractLaunchAngle() { this->launchAngle -= 0.05; }    // angle of the howitzer };
        /* No worky*/


private:

    Projectile* projectileInstance = new Projectile();
    Position  ptHowitzer;          // location of the howitzer
    Position  ptUpperRight;        // size of the screen
    Ground ground;
    double launchAngle;                  // angle of the howitzer 
    double time;

};
