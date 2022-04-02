#include "projectile.h"

#include "position.h"




/*************************************************************************
 *
 *
 *************************************************************************/
void Projectile::refreshProjectileTail()
{
	projectileTail.insert(projectileTail.begin(), *this->getCurrentPointLocation());

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
	this->getCurrentPointLocation()->setMetersX(launchLocation.getMetersX());
	this->getCurrentPointLocation()->setMetersY(launchLocation.getMetersY());

	/*****************************************************************
	* The reason why we have the get initl velocity inside the acceleration
	* Instanace is because the equation for acceleration is (acc = velocity / time)
	* The intil acceleration of the projectile is intial velocity / 1.
	*****************************************************************/


	accelerationInstance->setDDx(sin(launchAngle) * muzzleVelocity);
	accelerationInstance->setDDy(cos(launchAngle) * muzzleVelocity);



	velocityInstance->setDx(sin(launchAngle) * muzzleVelocity);
	velocityInstance->setDy(cos(launchAngle) * muzzleVelocity);

}





void Projectile::applyPhysics()
{
	/************************************************************
	These systems need to be intergrate. Note all systems are passed by point, so the values
	passed into the methods will be changed and alter with in each of the methods
	************************************************************/
	//cout << accelerationInstance->getDDy() << endl;
	EnvironmentalConstants().applyDrag(accelerationInstance, velocityInstance, currentLocation, PROJECTILEINITMASS, PROJECTILERADIUS);
	EnvironmentalConstants().applyGravity(accelerationInstance);  // Apply gravity to projectile based on its current altitude
	EnvironmentalConstants().applyIniteria(accelerationInstance, velocityInstance, currentLocation); // Apply initeria to the projectile

}






