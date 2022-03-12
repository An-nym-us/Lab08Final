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
		test_applyGravity_1();
		test_applyGravity_2();
		test_applyGravity_3();
		test_applyGravity_4();
	}

	bool closeEnough(double input, double lowerRange, double upperRange)
	{
		if (input > lowerRange && input < upperRange)
		{
			return true;
		}
		else
		{
			return false;
		}

	}




	/*****************************************************************
	* All Test Case Go Below Here
	*****************************************************************/
	void test_applyGravity_1()
	{
		// Set up
		Environment instance;
		Position* point = new Position();
		point->setMetersY(10);

		// Exercise
		instance.applyGravity(point);


		// verify
		assert(closeEnough(point->getMetersY(), 0, 1));

		//Teardown

	}


	void test_applyGravity_2()
	{
		// Set up
		Environment instance;
		Position* point = new Position();
		point->setMetersY(100);

		// Exercise
		instance.applyGravity(point);

		// verify
		assert(closeEnough(point->getMetersY(), 90, 100));

		//Teardown

	}

	void test_applyGravity_3()
	{
		// Set up
		Environment instance;
		Position* point = new Position();
		point->setMetersY(1000);

		// Exercise
		instance.applyGravity(point);

		// verify
		assert(closeEnough(point->getMetersY(), 990, 1000));

		//Teardown

	}

	void test_applyGravity_4()
	{
		// Set up
		Environment instance;
		Position* point = new Position();
		point->setMetersY(0);

		// Exercise
		instance.applyGravity(point);

		// verify
		assert(closeEnough(point->getMetersY(), -10, 0));

		//Teardown

	}


	};
