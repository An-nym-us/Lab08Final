#pragma once
#include "position.h"
#include "acceleration.h"
#include "velocity.h"
#include <vector>



using namespace std;

class Environment
{
	friend class TestEnvironment;




public:	

	double getDragAccelerationAtPosition(Position &position); // Returned in M/S^2 (acceleration)
	void applyGravity(Acceleration* currentAcceleration);
	void applyIniteria(Acceleration* currentAcceleration, Velocity* currentVelocity, Position* currentProjectilePosition);
	void applyDrag(Acceleration* currentAcceleration, Velocity* currentVelocity, Position* currentProjectilePosition);



private:
	double getForceOnSheelDueToDrag(double altitude, double mass /*In Kilograms*/, double velocity, double surfaceArea /*In meters*/); // Returned in Newtons


};
