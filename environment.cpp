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

void Environment::applyGravity(Acceleration* position)
{

	//Position storestate; 

	//storestate.setMetersY(EnvironmentalConstants().getGravityAtAltitude(position->getDDy()));

	position->addDDY(EnvironmentalConstants().getGravityAtAltitude(position->getDDy()));
	
}

void Environment::applyIniteria(Position& position)
{


}

void Environment::applyDrag(Position* position)
{


}
