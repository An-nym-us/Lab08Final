/***********************************************************************
 * Source File:
 *    
 * Author:
 *    
 * Summary:
 *    
 ************************************************************************/

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
        time(7.77),
        launchAngle(0.0)
    {
        ptHowitzer.setPixelsX(Position(ptUpperRight).getPixelsX() / 2.0);
        ptHowitzer.setPixelsY(Position(ptUpperRight).getPixelsY() / 4.0);
        ground.reset(ptHowitzer);
        isSimulationActive = false;
        simulationPreFlightcheck = false;
    }




    Projectile* getProjectile() { return projectileInstance; }
    Ground getGround() { return ground; }
    Position getptHowitzer() { return ptHowitzer; }
    Position getptUpperRight() { return ptUpperRight; }



    void activeSimulationTickProgression();
    void displayScreen();
    void gameStateProjectileStatus();


    /* current timer of the hang time of the proejctile  */
    void advanceTimer() { time += .5; }
    void resetTimer() { time = 0; }
    double getTimer() { return time; }

    /* Status of current simulation */
    bool isSimActive() { return isSimulationActive; }
    void activateSimulation() { isSimulationActive = true; }
    void deactivateSimulation() { isSimulationActive = false; }


    /* Pre flight check status before simulation is activated */
    bool isPreFlightCheckComplete() { return simulationPreFlightcheck; }
    void activatePreFlightCheck();
    void deactivatePreFlightCheck() { simulationPreFlightcheck = false; }


    /* Adjust and return projectile launch angle */
    double getLaunchAngle() { return launchAngle; }
    void advanceLaunchAngleFullStep() { this->launchAngle += 0.03; }
    void decrementLaunchAngleFullStep() { this->launchAngle -= 0.03; }    // angle of the howitzer };
    void advanceLaunchAngleHalfStep() { this->launchAngle +=     this->launchAngle >= 0 ? -0.002 : 0.002; }
    void decrementLaunchAngleHalfStep() { this->launchAngle +=   this->launchAngle >= 0 ? 0.002 : -0.002; }



private:

    Projectile* projectileInstance = new Projectile();
    Position  ptHowitzer;          // location of the howitzer
    Position  ptUpperRight;        // size of the screen
    Ground ground;
    double launchAngle;                  // angle of the howitzer 
    double time;
    bool isSimulationActive;
    bool simulationPreFlightcheck;


};
