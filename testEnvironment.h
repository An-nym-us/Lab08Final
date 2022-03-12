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
		bool value = false;

		// Exercise
		instance.applyGravity(point);

		if (closeEnough(point->getMetersY(), 0, 1))
			value = true;

		// verify
		assert(value == true);

		//Teardown

	}


	void test_applyGravity_2()
	{
		// Set up
		Environment instance;
		Position* point = new Position();
		point->setMetersY(100);
		bool value = false;

		// Exercise
		instance.applyGravity(point);
		if (closeEnough(point->getMetersY(), 90, 100))
			value = true;

		// verify
		assert(value == true);

		//Teardown

	}

	void test_applyGravity_3()
	{
		// Set up
		Environment instance;
		Position* point = new Position();
		point->setMetersY(1000);
		bool value = false;

		// Exercise
		instance.applyGravity(point);
		if (closeEnough(point->getMetersY(), 990, 1000))
			value = true;

		// verify
		assert(value == true);

		//Teardown

	}

	void test_applyGravity_4()
	{
		// Set up
		Environment instance;
		Position* point = new Position();
		point->setMetersY(0);
		bool value = false;

		// Exercise
		instance.applyGravity(point);
		if (closeEnough(point->getMetersY(), -10, 0))
			value = true;

		// verify
		assert(value == true);

		//Teardown

	}


	};
