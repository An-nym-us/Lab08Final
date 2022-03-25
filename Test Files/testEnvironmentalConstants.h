#pragma once


#include <iostream>
#include <vector>
#include "position.h"
#include "environmentalConstants.h"
#include <cassert>


using namespace std;

class TestEnvironmentalConstants
{
public:
	void run()
	{
		// test find lower bounds function
		test_lower_bounds_0();
		test_lower_bounds_1();
		test_lower_bounds_2();
		test_lower_bounds_3();
		test_lower_bounds_4();
		test_lower_bounds_5();


		// test find upper bounds function
		test_upper_bounds_0();
		test_upper_bounds_1();
		test_upper_bounds_2();
		test_upper_bounds_3();
		test_upper_bounds_4();
		test_upper_bounds_5();
		test_upper_bounds_6();
		test_upper_bounds_7();
		test_upper_bounds_8();


		// double based linear interpolation testing function overloading
		test_same_point();
		test_middle_x_change();
		test_middle_both_change();
		test_forward_one_side();
		test_forward_other_side();
		test_backward_one_side();
		test_backward_other_side();


		// vector based linear interpolation testing function overloading
		test_same_point_vector();
		test_middle_x_change_vector();
		test_middle_both_change_vector();
		test_forward_one_side_vector();
		test_forward_other_side_vector();
		test_backward_one_side_vector();
		test_backward_other_side_vector();
	}

	/*****************************************************************
	* All Test Case Go Below Here
	*****************************************************************/




	//Test Lowest bound for data table
	void test_lower_bounds_0()
	{
		// Set up
		EnvironmentalConstants instance;
		vector<double> desiredOuput{ 1,1 };
		double inputValue = 1;
		vector<vector<double>> inputTable{ {0,0}, {1,1}, {2,2} };

		// Exercise

		// verify
		assert(instance.findLowerBound(inputValue, inputTable) == desiredOuput);

		//Teardown

	}


	//Test Lowest bound for data table
	// If the input value is directly lined up with a 
	// index in the vector, return that exact index.
	void test_lower_bounds_1()
	{
		// Set up
		EnvironmentalConstants instance;
		vector<double> desiredOuput{ 3,3 };
		double inputValue = 3;
		vector<vector<double>> inputTable{ {1,1}, {2,2}, {3,3} };

		// Exercise

		// verify
		assert(instance.findLowerBound(inputValue, inputTable) == desiredOuput);

		//Teardown

	}

	//Test Lowest bound for data table
	void test_lower_bounds_2()
	{
		// Set up
		EnvironmentalConstants instance;
		vector<double> desiredOuput{ 1,1 };
		double inputValue = 1.5;
		vector<vector<double>> inputTable{ {0,0}, {1,1} , {2,2} };
		// Exercise

		// verify
		assert(instance.findLowerBound(inputValue, inputTable) == desiredOuput);

		//Teardown

	}

	//Test Lowest bound for data table
	void test_lower_bounds_3()
	{
		// Set up
		EnvironmentalConstants instance;
		vector<double> desiredOuput{ 1,1 };
		double inputValue = 1.9;
		vector<vector<double>> inputTable{ {0,0}, {1,1} , {2,2} };

		// Exercise

		// verify
		assert(instance.findLowerBound(inputValue, inputTable) == desiredOuput);

		//Teardown


	}

	//Test Lowest bound for data table
	void test_lower_bounds_4()
	{
		// Set up
		EnvironmentalConstants instance;
		vector<double> desiredOuput{ 1,1 };
		double inputValue = 1.2;
		vector<vector<double>> inputTable{ {0,0}, {1,1} , {2,2} };

		// Exercise

		// verify
		assert(instance.findLowerBound(inputValue, inputTable) == desiredOuput);

		//Teardown

	}

	//Test Lowest bound for data table
	void test_lower_bounds_5()
	{
		// Set up
		EnvironmentalConstants instance;
		vector<double> desiredOuput{ 200,300 };
		double inputValue = 205;
		vector<vector<double>> inputTable{ {0,0}, {80,213}, {90,303}, {100,213}, {150,250},       {200,300}, {3000,3603} };

		// Exercise
		// 
		// verify
		assert(instance.findLowerBound(inputValue, inputTable) == desiredOuput);

		//Teardown


	}




	/*****************************************************************
	* All Test Cases for Upper bounds method.
	*****************************************************************/

	//Test upper bound for data table
	void test_upper_bounds_0()
	{
		// Set up
		EnvironmentalConstants instance;
		vector<double> desiredOuput{ 1,1 };
		double inputValue = 1;
		vector<vector<double>> inputTable{ {0,0}, {1,1}, {2,2} };

		// Exercise

		// verify
		assert(instance.findUpperBound(inputValue, inputTable) == desiredOuput);

		//Teardown

	}

	//Test upper bound for data table
	void test_upper_bounds_1()
	{
		// Set up
		EnvironmentalConstants instance;
		vector<double> desiredOuput{ 2,2 };
		double inputValue = 2;
		vector<vector<double>> inputTable{ {0,0}, {1,1}, {2,2} };


		// Exercise

		// verify
		assert(instance.findUpperBound(inputValue, inputTable) == desiredOuput);

		//Teardown


	}

	//Test upper bound for data table
	void test_upper_bounds_2()
	{
		// Set up
		EnvironmentalConstants instance;
		vector<double> desiredOuput{ 2,2 };
		double inputValue = 1.5;
		vector<vector<double>> inputTable{ {0,0}, {1,1}, {2,2} };

		// Exercise

		// verify
		assert(instance.findUpperBound(inputValue, inputTable) == desiredOuput);

		//Teardown

	}

	//Test upper bound for data table
	void test_upper_bounds_3()
	{
		// Set up
		EnvironmentalConstants instance;
		vector<double> desiredOuput{ 2,2 };
		double inputValue = 1.6;
		vector<vector<double>> inputTable{ {0,0}, {1,1}, {2,2} };

		// Exercise
		// 
		// verify
		assert(instance.findUpperBound(inputValue, inputTable) == desiredOuput);

		//Teardown

	}

	//Test upper bound for data table
	void test_upper_bounds_4()
	{
		// Set up
		EnvironmentalConstants instance;
		vector<double> desiredOuput{ 2,2 };
		double inputValue = 1.4;
		vector<vector<double>> inputTable{ {0,0}, {1,1}, {2,2} };

		// Exercise

		// verify
		assert(instance.findUpperBound(inputValue, inputTable) == desiredOuput);

		//Teardown

	}

	//Test upper bound for data table
	void test_upper_bounds_5()
	{
		// Set up
		EnvironmentalConstants instance;
		vector<double> desiredOuput{ 150,250 };
		double inputValue = 120;
		vector<vector<double>> inputTable{ {0,0}, {80,213}, {90,303}, {100,213}, {150,250}, {200,300}, {3000,3603} };


		// Exercise

		// verify
		assert(instance.findUpperBound(inputValue, inputTable) == desiredOuput);

		//Teardown

	}

	//Test upper bound for data table
	void test_upper_bounds_6()
	{
		// Set up
		EnvironmentalConstants instance;
		vector<double> desiredOuput{ 90,303 };
		double inputValue = 21;
		vector<vector<double>> inputTable{ {0,0}, {20,213}, {90, 303}, {100,213} };
		// Exercise

		// verify
		assert(instance.findUpperBound(inputValue, inputTable) == desiredOuput);

		//Teardown

	}

	//Test upper bound for data table
	void test_upper_bounds_7()
	{
		// Set up
		EnvironmentalConstants instance;
		vector<double> desiredOuput{ 0,0 };
		double inputValue = 0;
		vector<vector<double>> inputTable{ {0,0}, {20,213}};
		// Exercise

		// verify
		assert(instance.findUpperBound(inputValue, inputTable) == desiredOuput);

		//Teardown

	}

	//Test upper bound for data table
	void test_upper_bounds_8()
	{
		// Set up
		EnvironmentalConstants instance;
		vector<double> desiredOuput{ 90,303 };
		double inputValue = 90;
		vector<vector<double>> inputTable{ {0,0}, {20,213}, {90, 303}};


		// Exercise

		// verify
		assert(instance.findUpperBound(inputValue, inputTable) == desiredOuput);

		//Teardown

	}




	/*****************************************************************
	* Double Linear Interpolation Testing (function overloading)
	*****************************************************************/

	void test_same_point()
	{
		// set up
		EnvironmentalConstants envInstance;

		bool value = false;
		// exercise
		if (envInstance.interpolation(0.0, 0.0, 0.0, 0.0, 0.0) == 0.0)
			value = true;

		// verify
		assert(value == true);

		// teardown


	}

	void test_middle_x_change()
	{
		// set up

		EnvironmentalConstants envInstance;

		bool value = false;

		// exercise

		if (envInstance.interpolation(0.0, 0.0, 2.0, 0.0, 1.00) == 0.00)
			value = true;

		// verify
		assert(value == true);

		// teardown


	}

	void test_middle_both_change()
	{
		// setup

		EnvironmentalConstants envInstance;
		bool value = false;

		// exercise

		if (envInstance.interpolation(0.0, 0.0, 2.0, 2.0, 1.00) == 1.00)
			value = true;

		// verify
		assert(value == true);

		// teardown

	}

	void test_forward_one_side()
	{
		// setup

		EnvironmentalConstants envInstance;
		bool value = false;

		// exercise

		if (envInstance.interpolation(1.0, 2.0, 2.0, 3.0, 1.25) == 2.25)
			value = true;

		// verify
		assert(value == true);

		// teardown

	}

	void test_forward_other_side()
	{
		// setup

		EnvironmentalConstants envInstance;
		bool value = false;

		// exercise

		if (envInstance.interpolation(1.0, 2.0, 2.0, 3.0, 1.75) == 2.75)
			value = true;

		// verify
		assert(value == true);

		// teardown

	}

	void test_backward_one_side()
	{
		// setup

		EnvironmentalConstants envInstance;
		bool value = false;

		// exercise

		if (envInstance.interpolation(2.0, 2.0, 1.0, 3.0, 1.50) == 2.50)
			value = true;

		// verify
		assert(value == true);

		// teardown

	}

	void test_backward_other_side()
	{
		// setup

		EnvironmentalConstants envInstance;
		bool value = false;

		// exercise

		if (envInstance.interpolation(2.0, 2.0, 1.0, 3.0, 1.75) == 2.25)
			value = true;

		// verify
		assert(value == true);

		// teardown
	}


	/*****************************************************************
	* Vector Linear Interpolation Testing (function overloading)
	*****************************************************************/

	void test_same_point_vector()
	{
		// set up
		EnvironmentalConstants envInstance;

		// exercise

		// verify
		assert(envInstance.interpolation({ 0.0, 0.0 }, { 0.0, 0.0 }, 0.0) == 0.0);

		// teardown

	}

	void test_middle_x_change_vector()
	{
		// set up
		EnvironmentalConstants envInstance;

		// exercise

		// verify
		assert(envInstance.interpolation({ 0.0, 0.0 }, { 2.0, 0.0 }, 1.00) == 0.00);

		// teardown


	}

	void test_middle_both_change_vector()
	{
		// setup
		EnvironmentalConstants envInstance;

		// exercise

		// verify
		assert(envInstance.interpolation({ 0.0, 0.0 }, { 2.0, 2.0 }, 1.00) == 1.00);

		// teardown

	}

	void test_forward_one_side_vector()
	{
		// setup

		EnvironmentalConstants envInstance;

		// exercise

		// verify
		assert(envInstance.interpolation({ 1.0, 2.0 }, { 2.0, 3.0 }, 1.25) == 2.25);

		// teardown

	}

	void test_forward_other_side_vector()
	{
		// setup

		EnvironmentalConstants envInstance;

		// exercise

		// verify
		assert(envInstance.interpolation({ 1.0, 2.0 }, { 2.0, 3.0 }, 1.75) == 2.75);

		// teardown

	}

	void test_backward_one_side_vector()
	{
		// setup

		EnvironmentalConstants envInstance;

		// exercise

		// verify
		assert(envInstance.interpolation({ 2.0, 2.0 }, { 1.0, 3.0 }, 1.50) == 2.50);

		// teardown

	}

	void test_backward_other_side_vector()
	{
		// setup
		EnvironmentalConstants envInstance;

		// exercise
		
		// verify
		assert(envInstance.interpolation({ 2.0, 2.0 }, { 1.0, 3.0 }, 1.75) == 2.25);

		// teardown
	}
};
