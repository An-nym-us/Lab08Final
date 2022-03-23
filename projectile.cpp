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

	cout << angle << "is convert " << endl;

	/*****************************************************************
	* The reason why we have the get initl velocity inside the acceleration
	* Instanace is because the equation for acceleration is (acc = velocity / time)
	* The intil accelerationof the projectile is intial velocity / 1.
	*****************************************************************/
	accelerationInstance->setDDx(sin(angle) * getInitVelocity() / 1);
	accelerationInstance->setDDy(cos(angle) * getInitVelocity() / 1);

	velocityInstance->setDx(sin(angle) * getInitVelocity());
	velocityInstance->setDy(cos(angle) * getInitVelocity());

	


	cout << "launch Angle is: " << angle << endl;
	cout << "Set acceleration is: " << accelerationInstance->getDDy() << endl;
	cout << "\n";

}





void Projectile::applyPhysics()
{
	Environment().applyGravity(accelerationInstance);  // The gravity system is working as intended. As long as the class and input vlaues dont change this system works great.

	Environment().applyIniteria(accelerationInstance, velocityInstance, currentLocation);


	/************************************************************ 
	These systems need to be intergrate. Note all systems are passed by point, so the values 
	passed into the methods will be changed and alter with in each of the methods
	************************************************************/

	Environment().applyDrag(accelerationInstance, velocityInstance, currentLocation, getMass(), getRadius());


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

