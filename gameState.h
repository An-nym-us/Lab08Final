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
#include "howitzer.h"

class GameState
{
public:
    //GameState(Position ptUpperRight);
    GameState(Position ptUpperRight)
            :ptUpperRight(ptUpperRight),    ground(ptUpperRight),    time(7.77)//, *howitzerInstance(ptUpperRight)
        {
            howitzerInstance = new Howitzer(ptUpperRight);
            isSimulationActive = false;
            simulationPreFlightcheck = false;
        }




    Projectile* getProjectile() { return projectileInstance; }
    Ground getGround() { return ground; }
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
    //void activatePreFlightCheck();
    void deactivatePreFlightCheck() { simulationPreFlightcheck = false; }


    /* Adjust and return projectile launch angle */




private:

    Projectile* projectileInstance = new Projectile();
    Howitzer* howitzerInstance; //= new Howitzer(ptUpperRight);
    Position  ptUpperRight;        // size of the screen
    Ground ground;
               // angle of the howitzer 
    double time;
    bool isSimulationActive;
    bool simulationPreFlightcheck;


};
