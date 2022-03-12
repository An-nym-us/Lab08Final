#pragma once
#include "position.h"
#include <vector>



using namespace std;

class Environment
{
	friend class TestEnvironment;




public:	

	double getDragAccelerationAtPosition(Position &position); // Returned in M/S^2 (acceleration)
	void applyGravity(Position* position);
	void applyIniteria(Position* position);
	void applyDrag(Position* position);



private:
	double getForceOnSheelDueToDrag(double altitude, double mass /*In Kilograms*/, double velocity, double surfaceArea /*In meters*/); // Returned in Newtons


};
