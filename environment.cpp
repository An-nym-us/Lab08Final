#include "environment.h"
#include "environmentalConstants.h"
#include <iostream>
#include <cmath>  





/*****************************************************************
*
*
*****************************************************************/
double Environment::getForceOnSheelDueToDrag(double altitude, double velocity, double surfaceArea)
{
	double mach = velocity / EnvironmentalConstants().getSpeedOfSoundAtAltitude(altitude);// <=== OMG THIS WORKS!!!!   :D
	double dragCoe = EnvironmentalConstants().getDragCoefficientAtMach(mach);// <=== OMG THIS WORKS!!!!   :D
	double p = EnvironmentalConstants().getDensityAtAltitude(altitude);// <=== OMG THIS WORKS!!!!   :D



	return .5 * dragCoe * p * (velocity * velocity) * surfaceArea;

}




/*****************************************************************
*
*
*****************************************************************/
double Environment::getDragAccelerationAtPosition(Velocity& currentVelocity, Position& currentProjectilePosition , double mass, double radius)
{
	double currentAltitude = currentProjectilePosition.getMetersY();
	double velocity = currentVelocity.getSpeed();
	double surfaceArea = 3.1415927 * radius * radius;

	double currentForce = getForceOnSheelDueToDrag(currentAltitude, velocity, surfaceArea);

	return (currentForce / mass);
}



void Environment::applyGravity(Acceleration* position)
{
	position->addDDY(EnvironmentalConstants().getGravityAtAltitude(position->getDDy()));
}



void Environment::applyIniteria(Acceleration* currentAcceleration, Velocity* currentVelocity, Position* currentProjectilePosition)
{
	currentVelocity->setDx(currentAcceleration->getDDx() * .5);
	currentVelocity->setDy(currentAcceleration->getDDy() * .5);

	double timedil = .5;
	double temp = currentProjectilePosition->getMetersY() + (currentVelocity->getDy() * timedil) + (.5 * currentAcceleration->getDDy() * (timedil * timedil) );

	currentProjectilePosition->setMetersY(temp);

	double temp2 = currentProjectilePosition->getMetersX() + (currentVelocity->getDx() * timedil) + (.5 * currentAcceleration->getDDx() * (timedil * timedil));
	currentProjectilePosition->setMetersX(temp2);

}



void Environment::applyDrag(Acceleration* currentAcceleration, Velocity* currentVelocity, Position* currentProjectilePosition, double mass, double radius)
{
	double accelerationDueToDrag =	(-1) * getDragAccelerationAtPosition(*currentVelocity, *currentProjectilePosition, mass, radius);


	/* This will get the current angle of attack of the projectile to be used to used in the apply drag system*/
	double currentAngleOfTravel = atan(currentVelocity->getDx()/ currentVelocity->getDy() );  




	/* Get the current X,Y acceleration of the projectile */
	double tempStateDDX = currentAcceleration->getDDx();
	double tempStateDDY = currentAcceleration->getDDy();

	/* Refresh the new acceleration based on the angle of travel */
	tempStateDDX = tempStateDDX + sin(currentAngleOfTravel) * accelerationDueToDrag;
	tempStateDDY = tempStateDDY + cos(currentAngleOfTravel) * accelerationDueToDrag;

	/* Update the acceleration */
	currentAcceleration->setDDx(tempStateDDX);
	currentAcceleration->setDDy(tempStateDDY);

}
