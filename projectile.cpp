#include "projectile.h"
#include "environment.h"
#include "environmentalConstants.h"

#include "position.h"





void Projectile::refreshProjectileTail()
{
	projectileTail.insert(projectileTail.begin(), this->getCurrentPointLocation());

	if (projectileTail.size() > 19)
	{
		projectileTail.pop_back();
	}


}


Position& Projectile::getProjectileTail(double j)
{
	for (int i = 0; i < 20; i++)
	{
		if (i == j && i < projectileTail.size())
		{
			return projectileTail[i];
		}
	}


}



/*
* all init launch data includding velocity, acceration, and direction.
*/
void Projectile::initializeProjectileLaunchState(double launchAngle, Position const&  launchLocation ) 
{
	this->setCurrentLocationX(launchLocation.getMetersX());
	this->setCurrentLocationY(launchLocation.getMetersY());

	/*****************************************************************
	* The reason why we have the get initl velocity inside the acceleration
	* Instanace is because the equation for acceleration is (acc = velocity / time)
	* The intil acceleration of the projectile is intial velocity / 1.
	*****************************************************************/


	accelerationInstance->setDDx(sin(launchAngle) * PROJECTILEINITVELOCITY / 1);
	accelerationInstance->setDDy(cos(launchAngle) * PROJECTILEINITVELOCITY / 1);

	velocityInstance->setDx(sin(launchAngle) * PROJECTILEINITVELOCITY);
	velocityInstance->setDy(cos(launchAngle) * PROJECTILEINITVELOCITY);

}





void Projectile::applyPhysics()
{
	Environment().applyGravity(accelerationInstance);  // The gravity system is working as intended. As long as the class and input vlaues dont change this system works great.
	Environment().applyIniteria(accelerationInstance, velocityInstance, currentLocation);


	/************************************************************ 
	These systems need to be intergrate. Note all systems are passed by point, so the values 
	passed into the methods will be changed and alter with in each of the methods
	************************************************************/

	Environment().applyDrag(accelerationInstance, velocityInstance, currentLocation, PROJECTILEINITMASS, PROJECTILERADIUS);


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

