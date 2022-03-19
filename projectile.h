#pragma once
#include "position.h"
#include <vector>
#include "uiDraw.h"
#include "velocity.h"
#include "acceleration.h"
#include "environment.h"

class Projectile
{
public:
    Projectile()
    {
        //currentLocation.setPixelsX(0);
        //currentLocation.setPixelsY(0);
    }





    void noDDestroy()
    {
        //testing = testing + 1;
        ////cout << currentLocation.getMetersX() << endl;
        //cout << testing << endl;
        ////currentLocation.addMetersX(-1);
        ////currentLocation.addMetersY(-1);


    }


    void applyPhysics();
    void applyLaunchPhysics(double angle);


    double getCurrentLocationX();
    double getCurrentLocationY();
    void setCurrentLocationX(double X);
    void setCurrentLocationY(double Y);







    /* We can remvoe this from here This is to stay in the callback or placed in the gamestate*/
    //void draw(ogstream &gout) const;
    //    void advance(double time);



    bool flying();
    double getAltitude();


    double getFlightDistance();
    double getSpeed();
    double getCurrentTime();


    /*  We can keep these for now, But i dont believe that we will need these*/
    double getMass() { return MASS; }
    double getRadius() { return RADIUS;  }
    double getInitVelocity() { return INITVELOCITY; }
    
private:
    const double MASS = 46.7; // In KG
    const double RADIUS = .15489 / 2.00; // In meters
    const double INITVELOCITY = 827;





    //These classes will never be destroy. all information contaied in them are safe to access and chagne at any time
    Position* currentLocation = new Position(); // the current loction of the object in world space.
    Velocity* velocityInstance = new Velocity();
    Acceleration* accelerationInstance = new Acceleration();

};
