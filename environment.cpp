#include "environment.h"
#include "environmentalConstants.h"
#include <iostream>
#include <cmath>  
using namespace std;




/*****************************************************************
*
*
*****************************************************************/
double Environment::getForceOnSheelDueToDrag(double altitude, double mass, double velocity, double surfaceArea)
{
	double mach = velocity / EnvironmentalConstants().getSpeedOfSoundAtAltitude(altitude);
	double dragCoe = EnvironmentalConstants().getDragCoefficientAtMach(mach);
	double p = EnvironmentalConstants().getDensityAtAltitude(altitude);

	return .5 * dragCoe * p * (velocity * velocity) * surfaceArea;
}




/*****************************************************************
*
*
*****************************************************************/
double Environment::getDragAccelerationAtPosition(Position& position)
{
	return -1;


}

void Environment::applyGravity(Position* position)
{

	Position storestate; 
	//cout << EnvironmentalConstants().getGravityAtAltitude(position->getMetersY()) << endl;
	storestate.setMetersY(EnvironmentalConstants().getGravityAtAltitude(position->getMetersY()));
	position->addMetersY(storestate.getMetersY());
	
}

void Environment::applyIniteria(Position* position)
{


}

void Environment::applyDrag(Position* position)
{


}
