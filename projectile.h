/***********************************************************************
 * Header File:
 *    Projectile
 * Author:
 *    Jonathan Gunderson, Dahal Sulav
 * Summary:
 * 
 * 
 ************************************************************************/

#pragma once
#include "environmentalConstants.h"
#include "position.h"
#include <iostream>
#include <vector>
#include "uiDraw.h"
#include "velocity.h"
#include "acceleration.h"
using namespace std;




class Projectile
{
public:
    Projectile(const double muzzleVelocity)
    {
        this->muzzleVelocity = muzzleVelocity;
        currentLocation->setMetersX(0);
        currentLocation->setMetersY(0);
        projectileTail.resize(20);
        for (int i = 0; i < 20; i++)
        {
            projectileTail.at(i) = *currentLocation;
        }
    }


    


    void applyPhysics();
    void initializeProjectileLaunchState(double launchAngle, Position const& launchLocation);
    void refreshProjectileTail();

    double setMuzzleVelocity(double muzzleVelocity) { this->muzzleVelocity = muzzleVelocity; }

    Position& getProjectileTail(double i);
    Position* getCurrentPointLocation() { return currentLocation; }
    Velocity getVelocityInstance() { return *velocityInstance; }



    


private:
    const double PROJECTILEINITMASS = 46.7; // In KG
    const double PROJECTILERADIUS = 0.077445; // In meters
    double muzzleVelocity;

    
    vector<Position> projectileTail;



    //These classes will never be destroy. all information contaied in them are safe to access and chagne at any time
    Position* currentLocation = new Position(); // the current loction of the object in world space.
    Velocity* velocityInstance = new Velocity();
    Acceleration* accelerationInstance = new Acceleration();


};
