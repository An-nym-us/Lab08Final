#pragma once


#include <iostream>
#include "position.h"
#include "environment.h"
#include <cassert>


using namespace std;

class TestEnvironment
{
public:
	void run()
	{
		get_zero_alt();
	}





	//Testing the testing system case 1
	void get_zero_alt()
	{
		Environment tempinstnace;
		tempinstnace.changethis = 5;
		bool temp = false;

		int value = tempinstnace.error_checking_1(5);
		if (value == 25)
			temp = true;
		
		assert(temp == true);
	}

};