#include "projectile.h"
#include "environment.h"
#include "environmentalConstants.h"

#include "position.h"


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
	double value = currentLocation.getMetersY();
	//double currentVelocity = velocityInstance->getDy();
	//double currentacclereateion = accelerationInstance->getDDy();



	Environment().applyGravity(accelerationInstance);
	setCurrentLocationY(accelerationInstance->getDDy() + value);



}







double Projectile::getCurrentLocationX()
{
	return currentLocation.getMetersX();
}
double Projectile::getCurrentLocationY()
{
	return currentLocation.getMetersY();
}
void Projectile::setCurrentLocationX(double X)
{
	currentLocation.setMetersX(X);
}
void Projectile::setCurrentLocationY(double Y)
{
	currentLocation.setMetersY(Y);
}