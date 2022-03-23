#pragma once
#include <vector>



using namespace std;


class EnvironmentalConstants
{



public:



	double getDragCoefficientAtMach(double mach);
	double getDensityAtAltitude(double altitude);
	double getGravityAtAltitude(double altitude);
	double getSpeedOfSoundAtAltitude(double altitude);




	double interpolation(double d0, double r0, double d1, double r1, double d);
	double interpolation(vector<double> lowerBounds, vector<double> upperBounds, double targetValue);

private:

	vector<double> findLowerBound(double inputValue, vector<vector<double>> dataTable);
	vector<double> findUpperBound(double inputValue, vector<vector<double>> datatTable);



	vector<vector<double>> machDragCoeffiecientDataTable =
	{
		{.300,.1625},
		{.500, .1659},
		{.700, .2031},
		{.890, .2597},
		{.920, .3010},
		{.960, .3287},
		{.980, .4002},
		{1.000, .4258},
		{1.020, .4335},
		{1.060, .4483},
		{1.240, .4064},
		{1.530, .3663},
		{1.990, .2897},
		{2.870, .2297},
		{2.890, .2306},
		{5.000, .2656}
	};

	vector<vector<double>> altitudeAirDensityDataTable =
	{
		{0, 1.2250000},
		{1000, 1.1120000},
		{2000, 1.0070000},
		{3000, 0.9093000},
		{4000, 0.8194000},
		{5000, 0.7364000},
		{6000, 0.6601000},
		{7000, 0.5900000},
		{8000, 0.5258000},
		{9000, 0.4671000},
		{10000, 0.4135000},
		{15000, 0.1948000},
		{20000, 0.0889100},
		{25000, 0.0400800},
		{30000, 0.0184100},
		{40000, 0.0039960},
		{50000, 0.0010270},
		{60000, 0.0003097},
		{70000, 0.0000828},
		{80000, 0.0000185}
	};

	vector<vector<double>> altitudeSpeedOfSoundDataTable =
	{
		{0, 340},
		{1000, 336},
		{2000, 332},
		{3000, 328},
		{4000, 324},
		{5000, 320},
		{6000, 316},
		{7000, 312},
		{8000, 308},
		{9000, 303},
		{10000, 299},
		{15000, 295},
		{20000, 295},
		{25000, 295},
		{30000, 305},
		{40000, 324}
	};

};