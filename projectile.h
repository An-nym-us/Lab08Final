#pragma once
#include <iostream>
#include "position.h"

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
		testing = testing + 1;
		//cout << currentLocation.getMetersX() << endl;

		currentLocation.addMetersX(-1);
		//currentLocation.addMetersY(-1);

	}

	Position getCurrentLocation() { return currentLocation; }

private:
	double testing = 0;
	Position currentLocation;

};