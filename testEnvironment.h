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

        test_same_point();
        test_middle_x_change();
        test_middle_both_change();
        test_forward_one_side();
        test_forward_other_side();
        test_backward_one_side();
        test_backward_other_side();

	}


	/*****************************************************************
	* All Test Case Go Below Here
	*****************************************************************/


    
    void test_same_point()
    {
        // set up
        Environment envInstance;
        
        bool value = false;
        // exercise
        if(envInstance.interpolation_check(0.0, 0.0, 0.0, 0.0, 0.0) == 0.0)
            value = true;
        
        // verify
        assert(value == true);
        
        // teardown

    
    }
    
    void test_middle_x_change()
    {
        // set up
        
        Environment envInstance;
        
        bool value = false;
        
        // exercise
        
        if (envInstance.interpolation_check(0.0, 0.0, 2.0, 0.0, 1.00) == 0.00)
            value = true;
        
        // verify
        assert(value == true);
        
        // teardown
        
        
    }
    
    
    void test_middle_both_change()
    {
        // setup
        
        Environment envInstance;
        bool value = false;
        
        // exercise
        
        if(envInstance.interpolation_check(0.0, 0.0, 2.0, 2.0, 1.00) == 1.00)
            value = true;
        
        // verify
        assert(value == true);
        
        // teardown

    }
    
    void test_forward_one_side()
    {
        // setup
        
        Environment envInstance;
        bool value = false;
        
        // exercise
        
        if(envInstance.interpolation_check(1.0, 2.0, 2.0, 3.0, 1.25) == 2.25)
            value = true;
        
        // verify
        assert(value == true);
        
        // teardown

    }
    
    void test_forward_other_side()
    {
        // setup
        
        Environment envInstance;
        bool value = false;
        
        // exercise
        
        if(envInstance.interpolation_check(1.0, 2.0, 2.0, 3.0, 1.75) == 2.75)
            value = true;
        
        // verify
        assert(value == true);
        
        // teardown

    }
    
    void test_backward_one_side()
    {
        // setup
        
        Environment envInstance;
        bool value = false;
        
        // exercise
        
        if(envInstance.interpolation_check(2.0, 2.0, 1.0, 3.0, 1.50) == 2.50)
            value = true;
        
        // verify
        assert(value == true);
        
        // teardown

    }
    
    void test_backward_other_side()
    {
        // setup
        
        Environment envInstance;
        bool value = false;
        
        // exercise
        
        if(envInstance.interpolation_check(2.0, 2.0, 1.0, 3.0, 1.75) == 2.25)
            value = true;
        
        // verify
        assert(value == true);
        
        // teardown
    }
    

};
