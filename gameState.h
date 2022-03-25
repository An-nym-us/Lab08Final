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
#include "position.h"   // for POINT
#include <iostream>
#include <cmath>
#include "projectile.h"
#include "howitzer.h"

class GameState
{
public:
    GameState(Position ptUpperRight);


    Projectile* getProjectile() { return projectileInstance; }
    Howitzer* getHowitzer() { return howitzerInstance; }
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





private:

    Projectile* projectileInstance;
    Howitzer* howitzerInstance; 
    const double muzzleVelocity = 0;

    bool simulationPreFlightcheck;
    Position  ptUpperRight;      

    double time;
    bool isSimulationActive;



};
