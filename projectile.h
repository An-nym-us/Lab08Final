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
#include "position.h"
#include <vector>
#include "uiDraw.h"
#include "velocity.h"
#include "acceleration.h"
#include "environment.h"
#include <vector>




class Projectile
{
public:
    Projectile() 
    {

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


    double getLocationX();
    double getLocationY();
    void setCurrentLocationX(double X);
    void setCurrentLocationY(double Y);



    Position& getProjectileTail(double i);
    Position getCurrentPointLocation() { return *currentLocation; }
    Velocity getVelocityInstance() { return *velocityInstance; }



    


private:
    const double PROJECTILEINITMASS = 46.7; // In KG
    const double PROJECTILERADIUS = .15489 / 2.00; // In meters
    const double PROJECTILEINITVELOCITY = 827;

    
    vector<Position> projectileTail;



    //These classes will never be destroy. all information contaied in them are safe to access and chagne at any time
    Position* currentLocation = new Position(); // the current loction of the object in world space.
    Velocity* velocityInstance = new Velocity();
    Acceleration* accelerationInstance = new Acceleration();


};
