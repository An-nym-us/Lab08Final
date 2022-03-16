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



    Projectile();
    void advance(double time);
    void draw(ogstream &gout) const;
    bool flying();
    double getAltitude();
    double getFlightTime();
    double getFlightDistance();
    double getSpeed();
    double getCurrentTime();
    void setMass(double mass)
    {
        this -> mass = mass;
    }
    void setRadious(double radious)
    {
        this -> radious = radious;
    }
    
private:
    double mass;
    double radious;
    vector<int> flightPath;
}
	double testing = 0;
	Position currentLocation;

	//These classes will only be destroy once the projectile class is destroyed
	Velocity* velocityInstance = new Velocity();
	Acceleration* accelerationInstance = new Acceleration();

};