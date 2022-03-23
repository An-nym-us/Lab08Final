#include "projectile.h"
#include "environment.h"
#include "position.h"




/*************************************************************************
 *
 *
 *************************************************************************/
void Projectile::refreshProjectileTail()
{
	projectileTail.insert(projectileTail.begin(), this->getCurrentPointLocation());

	if (projectileTail.size() > 19)
	{
		projectileTail.pop_back();
	}
}

/*************************************************************************
 * 
 * 
 *************************************************************************/
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
	/************************************************************
	These systems need to be intergrate. Note all systems are passed by point, so the values
	passed into the methods will be changed and alter with in each of the methods
	************************************************************/

	Environment().applyDrag(accelerationInstance, velocityInstance, currentLocation, PROJECTILEINITMASS, PROJECTILERADIUS);
	Environment().applyGravity(accelerationInstance);  // Apply gravity to projectile based on its current altitude
	Environment().applyIniteria(accelerationInstance, velocityInstance, currentLocation); // Apply initeria to the projectile

}







double Projectile::getLocationX()
{
	return currentLocation->getMetersX();
}
double Projectile::getLocationY()
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

