#include "environmentalConstants.h"
#include <math.h>


using namespace std;


/*****************************************************************************************
* Find the lowest value bounds in a Vector Array
*****************************************************************************************/
vector<double> EnvironmentalConstants::findLowerBound(double inputValue, vector<vector<double>> dataTable) const
{
	vector<vector<double>> splitState = dataTable;
	

	for (int i = 0; i < splitState.size(); i++) 
	{
		// Bypass Loop if exact value Is Found.
		if (splitState.at(i).at(0) == inputValue)
		{
			return { splitState.at(i).at(0), splitState.at(i).at(1) };
		}



		// Start search for lowest bounds.
		if (!splitState.empty())
		{

			if ( (i-1) > 0)
			{
				double positiveCheckState = inputValue - splitState.at(i - 1).at(0); // This represents the Prevoius Index Value
				double negivateCheckState = inputValue - splitState.at(i).at(0);	// This is the current Index value


				/*****************************************************************************************
				* If the value given by the user is in between the values of two of the vector list index,
				* We can find its current loction and the lower bounds by doing comparison math.
				* If the current provided value, subtracted by the previous vector index, and the result
				* Is positive, as well as the input value subtracted next vector index value returns a 
				* Negiatve, we know that we found the state of the vector list where we are in 
				* between the two ideal values to return from this method.
				*****************************************************************************************/

				if (positiveCheckState > 0 && negivateCheckState < 0) 
				{
					return { splitState.at(i-1).at(0), splitState.at(i-1).at(1) };
				}
			}
		}
	}

	// FAIL Error
	return { -1,-1 };


}


/*****************************************************************************************
* Find the Highest value bounds in a Vector Array 
*****************************************************************************************/
vector<double> EnvironmentalConstants::findUpperBound(double inputValue, vector<vector<double>> dataTable) const
{
	vector<vector<double>> splitState = dataTable;


	for (int i = 0; i < splitState.size(); i++)
	{
		// Bypass Loop if exact value Is Found.
		if (splitState.at(i).at(0) == inputValue)
		{
			return { splitState.at(i).at(0), splitState.at(i).at(1) };
		}



		// Start search for lowest bounds.
		if (!splitState.empty())
		{

			if ((i + 1) < splitState.size())
			{
				double positiveCheckState = inputValue - splitState.at(i).at(0); // This represents the Prevoius Index Value
				double negivateCheckState = inputValue - splitState.at(i+1).at(0);	// This is the current Index value

				//cout << "PREVIOUS Index " << splitState.at(i + 1).at(0) << " AND " << splitState.at(i + 1).at(1) << endl;
				/*****************************************************************************************
				* If the value given by the user is in between the values of two of the vector list index,
				* We can find its current loction and the lower bounds by doing comparison math.
				* If the current provided value, subtracted by the previous vector index, and the result
				* Is positive, as well as the input value subtracted next vector index value returns a
				* Negiatve, we know that we found the state of the vector list where we are in
				* between the two ideal values to return from this method.
				*****************************************************************************************/

				if (positiveCheckState > 0 && negivateCheckState < 0)
				{
					return { splitState.at(i + 1).at(0), splitState.at(i + 1).at(1) };
				}
			}
		}
	}

	// FAIL Error
	return { -1,-1 };


}

/*****************************************************************
* Interpolation based on raw double values
*****************************************************************/
double EnvironmentalConstants::interpolation(double d0, double r0, double d1, double r1, double d) const
{
	double range = r0 + (r1 - r0) * (d - d0) / (d1 - d0);

	// checks if the value providedd by the lower bounds, upper boudnds and target value are all the same
	// if the are the same, return the exact index of the lower bounds, or upper bounds if wanted.
	if ((d0 == d) && (d1 == d))
		return r0;


	if (!isnan(range))
		return range;
	else
		return 0.0;
}


/*****************************************************************
* Interpilation based on vector inputs
*****************************************************************/
double EnvironmentalConstants::interpolation(vector<double> lowerBounds, vector<double> upperBounds, double targetValue) const
{
	double range = lowerBounds.at(1) + (targetValue - lowerBounds.at(0)) * ((upperBounds.at(1) - lowerBounds.at(1)) / (upperBounds.at(0) - lowerBounds.at(0)));

	// checks if the value providedd by the lower bounds, upper boudnds and target value are all the same
	// if the are the same, return the exact index of the lower bounds, or upper bounds if wanted.
	if ((lowerBounds.at(0) == targetValue) && (upperBounds.at(0) == targetValue))
		return lowerBounds.at(1);


	if (!isnan(range))
		return range;
	else
		return 0.0;
}


/*****************************************************************
* Find the air density based on the current altitude of the 
* Projectile by interpolating the data from within the 
* Air Density table
*****************************************************************/
double EnvironmentalConstants::getDensityAtAltitude(double altitude) const
{
	return interpolation( findLowerBound(altitude, altitudeAirDensityDataTable), findUpperBound(altitude, altitudeAirDensityDataTable), altitude );
}


/*****************************************************************
* Find the current Drag corefficient based on the current Mach value
*****************************************************************/
double EnvironmentalConstants::getDragCoefficientAtMach(double mach) const
{
	return interpolation(findLowerBound(mach, machDragCoeffiecientDataTable), findUpperBound(mach, machDragCoeffiecientDataTable), mach);
}


/*****************************************************************
* Calulate teh speed of sound based on the current altitude of
* the projcetile
*****************************************************************/
double EnvironmentalConstants::getSpeedOfSoundAtAltitude(double altitude) const
{
	return interpolation(findLowerBound(altitude, altitudeSpeedOfSoundDataTable), findUpperBound(altitude, altitudeSpeedOfSoundDataTable), altitude);
}



/*****************************************************************
* get the gravity of the prjectile based on the current altitude
* of the projcetile
*****************************************************************/
double EnvironmentalConstants::getGravityAtAltitude(double altitude) const
{
	return ((0.0000030799999999999985 * altitude) + 9.807) * -1;
}




/*****************************************************************
*
*
*****************************************************************/
double EnvironmentalConstants::getForceOnSheelDueToDrag(double altitude, double velocity, double surfaceArea)
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
double EnvironmentalConstants::getDragAccelerationAtPosition(Velocity& currentVelocity, Position& currentProjectilePosition, double mass, double radius)
{
	double currentAltitude = currentProjectilePosition.getMetersY();
	double velocity = currentVelocity.getSpeed();
	double surfaceArea = 3.1415927 * radius * radius;

	double currentForce = getForceOnSheelDueToDrag(currentAltitude, velocity, surfaceArea);

	return (currentForce / mass);
}



void EnvironmentalConstants::applyGravity(Acceleration* position)
{
	position->addDDY(EnvironmentalConstants().getGravityAtAltitude(position->getDDy()));
}



void EnvironmentalConstants::applyIniteria(Acceleration* currentAcceleration, Velocity* currentVelocity, Position* currentProjectilePosition)
{
	currentVelocity->setDx(currentAcceleration->getDDx() * .5);
	currentVelocity->setDy(currentAcceleration->getDDy() * .5);

	double timedil = .5;
	double temp = currentProjectilePosition->getMetersY() + (currentVelocity->getDy() * timedil) + (.5 * currentAcceleration->getDDy() * (timedil * timedil));

	currentProjectilePosition->setMetersY(temp);

	double temp2 = currentProjectilePosition->getMetersX() + (currentVelocity->getDx() * timedil) + (.5 * currentAcceleration->getDDx() * (timedil * timedil));
	currentProjectilePosition->setMetersX(temp2);

}



void EnvironmentalConstants::applyDrag(Acceleration* currentAcceleration, Velocity* currentVelocity, Position* currentProjectilePosition, double mass, double radius)
{
	double accelerationDueToDrag = (-1) * getDragAccelerationAtPosition(*currentVelocity, *currentProjectilePosition, mass, radius);


	/* This will get the current angle of attack of the projectile to be used to used in the apply drag system*/
	double currentAngleOfTravel = atan(currentVelocity->getDx() / currentVelocity->getDy());




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