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
        test_same_point();

	}


	/*****************************************************************
	* All Test Case Go Below Here
	*****************************************************************/


	//Testing the testing system case 1
	void get_zero_alt()
	{
		// set up
		Environment tempinstnace;
		tempinstnace.changethis = 5;
		bool value = false;


		// exercise
		if (tempinstnace.error_checking_1(5) == 25)
			value = true;

		// verify
		assert(value == true);


		// teardown
		delete& tempinstnace;
	}
    
    void test_same_point()
    {
        // set up
        Environment envInstance;
        
        bool value = false;
        // exercise
        if(envInstance.interpolation_check_same_point(0.0, 0.0, 0.0, 0.0, 0.0) == 0.0)
            value = true;
        
        // verify
        assert(value == true);
        
        // teardown
        delete& envInstance;
    
    }

};
