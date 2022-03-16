#pragma once
#include <iostream>
#include "position.h"
#include "velocity.h"
#include "acceleration.h"
#include "environment.h"

using namespace std;

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



private:
	double testing = 0;
	Position currentLocation;

	//These classes will only be destroy once the projectile class is destroyed
	Velocity* velocityInstance = new Velocity();
	Acceleration* accelerationInstance = new Acceleration();

};