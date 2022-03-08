#include "environmentalConstants.h"
#include <iostream>
#include <iterator>





using namespace std;

vector<double> EnvironmentalConstants::findLowerBound(double inputValue, vector<vector<double>> dataTable)
{
	vector<vector<double>> splitState = dataTable;
	vector<double> store;
	double index = 0;
	
	

	//for (int i = 0; i < splitState.size(); i++)
	for (auto i = splitState.begin(); i != splitState.end(); i++)
	{
		if (!splitState.empty())
		{
			index = i->at(0);
			// end search if the found value is exactly a value in the vector array.
			if (index == inputValue)
			{
				// this will end function search
				return { i->at(0), i->at(1) };
			}





			cout << i->at(0) << " and " << i->at(1) << endl;

		}
	}


	return { 2000,2010 };


}

