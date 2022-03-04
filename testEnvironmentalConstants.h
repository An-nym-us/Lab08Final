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
		get_zero_alt();

		test_lower_bounds_0();
		test_lower_bounds_1();
		test_lower_bounds_2();
		test_lower_bounds_3();
		test_lower_bounds_4();
		test_lower_bounds_5();

		test_upper_bounds_0();
		test_upper_bounds_1();
		test_upper_bounds_2();
		test_upper_bounds_3();
		test_upper_bounds_4();
		test_upper_bounds_5();


	}

	/*****************************************************************
	* All Test Case Go Below Here
	*****************************************************************/



	//Testing the testing system case 1
	void get_zero_alt()
	{
		//Set up
		EnvironmentalConstants tempinstnace;
		tempinstnace.changethis = 5;
		bool value = false;


		//Exercise
		if (tempinstnace.error_checking_1(5) == 25)
			value = true;

		//Verify
		assert(value == true);


		//Teardown
		delete& tempinstnace;
	}



	/*****************************************************************
	* All Test Cases for lower bounds method.
	*****************************************************************/


	//Test Lowest bound for data table
	void test_lower_bounds_0()
	{
		// Set up
		EnvironmentalConstants instance;
		vector<double> functionOutput{};
		vector<double> desiredOuput{ 1,1 };
		double inputValue = 1;
		vector<vector<double>> inputTable{ {0,0}, {1,1}, {2,2} };
		bool value = false;

		// Exercise
		functionOutput = instance.findLowerBound(inputValue, inputTable);
		if (functionOutput == desiredOuput)
			value = true;
		
		// verify
		assert(value == true);

		//Teardown
		delete& instance;

	}


	//Test Lowest bound for data table
	// If the input value is directly lined up with a 
	// index in the vector, return that exact index.
	void test_lower_bounds_1()
	{
		// Set up
		EnvironmentalConstants instance;
		vector<double> functionOutput{};
		vector<double> desiredOuput{ 3,3 };
		double inputValue = 3;
		vector<vector<double>> inputTable{ {1,1}, {2,2}, {3,3} };
		bool value = false;

		// Exercise
		functionOutput = instance.findLowerBound(inputValue, inputTable);
		if (functionOutput == desiredOuput)
			value = true;

		// verify
		assert(value == true);

		//Teardown
		delete& instance;

	}

	//Test Lowest bound for data table
	void test_lower_bounds_2()
	{
		// Set up
		EnvironmentalConstants instance;
		vector<double> functionOutput{};
		vector<double> desiredOuput{ 1,1 };
		double inputValue = 1.5;
		vector<vector<double>> inputTable{ {0,0}, {1,1} , {2,2} };
		bool value = false;


		// Exercise
		functionOutput = instance.findLowerBound(inputValue, inputTable);
		if (functionOutput == desiredOuput)
			value = true;

		// verify
		assert(value == true);

		//Teardown
		delete& instance;

	}

	//Test Lowest bound for data table
	void test_lower_bounds_3()
	{
		// Set up
		EnvironmentalConstants instance;
		vector<double> functionOutput{};
		vector<double> desiredOuput{ 1,1 };
		double inputValue = 1.6;
		vector<vector<double>> inputTable{ {0,0}, {1,1} , {2,2} };
		bool value = false;


		// Exercise
		functionOutput = instance.findLowerBound(inputValue, inputTable);
		if (functionOutput == desiredOuput)
			value = true;

		// verify
		assert(value == true);

		//Teardown
		delete& instance;

	}

	//Test Lowest bound for data table
	void test_lower_bounds_4()
	{
		// Set up
		EnvironmentalConstants instance;
		vector<double> functionOutput{};
		vector<double> desiredOuput{ 1,1 };
		double inputValue = 1.4;
		vector<vector<double>> inputTable{ {0,0}, {1,1} , {2,2} };
		bool value = false;


		// Exercise
		functionOutput = instance.findLowerBound(inputValue, inputTable);
		if (functionOutput == desiredOuput)
			value = true;

		// verify
		assert(value == true);

		//Teardown
		delete& instance;

	}

	//Test Lowest bound for data table
	void test_lower_bounds_5()
	{
		// Set up
		EnvironmentalConstants instance;
		vector<double> functionOutput{};
		vector<double> desiredOuput{ 0,0 };
		double inputValue = 0;
		vector<vector<double>> inputTable{ {0,0}, {1,1} , {2,2} };
		bool value = false;


		// Exercise
		functionOutput = instance.findLowerBound(inputValue, inputTable);
		if (functionOutput == desiredOuput)
			value = true;

		// verify
		assert(value == true);

		//Teardown
		delete& instance;

	}




	/*****************************************************************
	* All Test Cases for Upper bounds method.
	*****************************************************************/


	//Test upper bound for data table
	void test_upper_bounds_0()
	{
		// Set up
		EnvironmentalConstants instance;
		vector<double> functionOutput{};
		vector<double> desiredOuput{ 1,1 };
		double inputValue = 1;
		vector<vector<double>> inputTable{ {0,0}, {1,1}, {2,2} };
		bool value = false;

		// Exercise
		functionOutput = instance.findUpperBound(inputValue, inputTable);
		if (functionOutput == desiredOuput)
			value = true;

		// verify
		assert(value == true);

		//Teardown
		delete& instance;

	}

	//Test upper bound for data table
	void test_upper_bounds_1()
	{
		// Set up
		EnvironmentalConstants instance;
		vector<double> functionOutput{};
		vector<double> desiredOuput{ 2,2 };
		double inputValue = 2;
		vector<vector<double>> inputTable{ {0,0}, {1,1}, {2,2} };
		bool value = false;

		// Exercise
		functionOutput = instance.findUpperBound(inputValue, inputTable);
		if (functionOutput == desiredOuput)
			value = true;

		// verify
		assert(value == true);

		//Teardown
		delete& instance;

	}

	//Test upper bound for data table
	void test_upper_bounds_2()
	{
		// Set up
		EnvironmentalConstants instance;
		vector<double> functionOutput{};
		vector<double> desiredOuput{ 2,2 };
		double inputValue = 1.5;
		vector<vector<double>> inputTable{ {0,0}, {1,1}, {2,2} };
		bool value = false;

		// Exercise
		functionOutput = instance.findUpperBound(inputValue, inputTable);
		if (functionOutput == desiredOuput)
			value = true;

		// verify
		assert(value == true);

		//Teardown
		delete& instance;

	}

	//Test upper bound for data table
	void test_upper_bounds_3()
	{
		// Set up
		EnvironmentalConstants instance;
		vector<double> functionOutput{};
		vector<double> desiredOuput{ 2,2 };
		double inputValue = 1.6;
		vector<vector<double>> inputTable{ {0,0}, {1,1}, {2,2} };
		bool value = false;

		// Exercise
		functionOutput = instance.findUpperBound(inputValue, inputTable);
		if (functionOutput == desiredOuput)
			value = true;

		// verify
		assert(value == true);

		//Teardown
		delete& instance;

	}

	//Test upper bound for data table
	void test_upper_bounds_4()
	{
		// Set up
		EnvironmentalConstants instance;
		vector<double> functionOutput{};
		vector<double> desiredOuput{ 2,2 };
		double inputValue = 1.4;
		vector<vector<double>> inputTable{ {0,0}, {1,1}, {2,2} };
		bool value = false;

		// Exercise
		functionOutput = instance.findUpperBound(inputValue, inputTable);
		if (functionOutput == desiredOuput)
			value = true;

		// verify
		assert(value == true);

		//Teardown
		delete& instance;

	}

	//Test upper bound for data table
	void test_upper_bounds_5()
	{
		// Set up
		EnvironmentalConstants instance;
		vector<double> functionOutput{};
		vector<double> desiredOuput{ 0,0 };
		double inputValue = 0;
		vector<vector<double>> inputTable{ {0,0}, {1,1}, {2,2} };
		bool value = false;

		// Exercise
		functionOutput = instance.findUpperBound(inputValue, inputTable);
		if (functionOutput == desiredOuput)
			value = true;

		// verify
		assert(value == true);

		//Teardown
		delete& instance;

	}

};