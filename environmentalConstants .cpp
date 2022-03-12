#include "environmentalConstants.h"
#include <iostream>



using namespace std;


/*****************************************************************************************
* Find the lowest value bounds in a Vector Array
*****************************************************************************************/
vector<double> EnvironmentalConstants::findLowerBound(double inputValue, vector<vector<double>> dataTable)
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
vector<double> EnvironmentalConstants::findUpperBound(double inputValue, vector<vector<double>> dataTable)
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
*
*
*****************************************************************/
double EnvironmentalConstants::interpolation(double d0, double r0, double d1, double r1, double d)
{
	double range = r0 + (r1 - r0) * (d - d0) / (d1 - d0);

	// checks if the value providedd by the lower bounds, upper boudnds and target value are all the same
	// if the are the same, return the exact index of the lower bounds, or upper bounds if wanted.
	if ((d0 == d) && (d1 == d))
		return r0;


	if (!std::isnan(range))
		return range;
	else
		return 0.0;
}


/*****************************************************************
*
*
*****************************************************************/
double EnvironmentalConstants::interpolation(vector<double> lowerBounds, vector<double> upperBounds, double targetValue)
{
	double range = lowerBounds.at(1) + (targetValue - lowerBounds.at(0)) * ((upperBounds.at(1) - lowerBounds.at(1)) / (upperBounds.at(0) - lowerBounds.at(0)));

	// checks if the value providedd by the lower bounds, upper boudnds and target value are all the same
	// if the are the same, return the exact index of the lower bounds, or upper bounds if wanted.
	if ((lowerBounds.at(0) == targetValue) && (upperBounds.at(0) == targetValue))
		return lowerBounds.at(1);


	if (!std::isnan(range)) 
		return range;
	else
		return 0.0;
}


/*****************************************************************
*
*
*****************************************************************/
double EnvironmentalConstants::getDensityAtAltitude(double altitude)
{
	return interpolation( findLowerBound(altitude, altitudeAirDensityDataTable), findUpperBound(altitude, altitudeAirDensityDataTable), altitude );
}


/*****************************************************************
*
*
*****************************************************************/
double EnvironmentalConstants::getDragCoefficientAtMach(double mach)
{
	return interpolation(findLowerBound(mach, machDragCoeffiecientDataTable), findUpperBound(mach, machDragCoeffiecientDataTable), mach);
}


/*****************************************************************
*
*
*****************************************************************/
double EnvironmentalConstants::getSpeedOfSoundAtAltitude(double altitude) 
{
	return interpolation(findLowerBound(altitude, altitudeSpeedOfSoundDataTable), findUpperBound(altitude, altitudeSpeedOfSoundDataTable), altitude);
}



/*****************************************************************
*
*
*****************************************************************/
double EnvironmentalConstants::getGravityAtAltitude(double altitude)
{
	return ((0.0000030799999999999985 * altitude) + 9.807) * -1;
}




