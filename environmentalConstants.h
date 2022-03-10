#pragma once
#include <vector>



using namespace std;


class EnvironmentalConstants
{
	friend class TestEnvironmentalConstants;




public:

	vector<double> findLowerBound(double inputValue, vector<vector<double>>);

	vector<double> findUpperBound(double inputValue, vector<vector<double>>);

private:
	int changethis = 0;

	vector<vector<double>> developmentDataTable =
	{
		{0,0},
		{1,1},
		{2,2},
		{3,3},
		{4,4},
		{5,5}
	};

};