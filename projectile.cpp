#include "projectile.h"
#include "environment.h"
#include "environmentalConstants.h"

#include "position.h"



/*
* all init launch data includding velocity, acceration, and direction.
*/
void Projectile::applyLaunchPhysics(double angle)
{
	cout << "Lanuch physics called" << endl;
	accelerationInstance->setDDy(500);
	velocityInstance->setDy(1000);




	cout << "launch Angle is: " << angle << endl;
	cout << "Set acceleration is: " << accelerationInstance->getDDy() << endl;
	cout << "\n";

}





void Projectile::applyPhysics()
{
	double tempvalue = currentLocation->getMetersY();


	Environment().applyGravity(accelerationInstance);  // The gravity system is working as intended. As long as the class and input vlaues dont change this system works great.



	/************************************************************ 
	These systems need to be intergrate. Note all systems are passed by point, so the values 
	passed into the methods will be changed and alter with in each of the methods
	************************************************************/
	Environment().applyIniteria(accelerationInstance, velocityInstance, currentLocation);
	Environment().applyDrag(accelerationInstance, velocityInstance, currentLocation);


	/* part debug but also part keep state.*/ 
	setCurrentLocationY(accelerationInstance->getDDy() + tempvalue);
	//setCurrentLocationX(accelerationInstance->getDDx() + 1);



}







double Projectile::getCurrentLocationX()
{
	return currentLocation->getMetersX();
}
double Projectile::getCurrentLocationY()
{
	return currentLocation->getMetersY();
}
void Projectile::setCurrentLocationX(double X)
{
	currentLocation->setMetersX(X);
}
void Projectile::setCurrentLocationY(double Y)
{
	currentLocation->setMetersY(Y);
}