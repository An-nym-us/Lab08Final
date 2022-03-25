
#pragma once

#include <iostream>
#include "velocity.h"
#include <cassert>

using namespace std;

class TestVelocity
{
public:
    void run()
    {
        test_Velocity_Default();
        test_Velocity_NonDefault();
        test_Velocity_AddDx();
        test_Velocity_AddDy();
        test_Velocity_SetDX();
        test_Velocity_SetDY();
    };



/*****************************************************************
* All Test Case Go Below Here
*****************************************************************/
    void test_Velocity_Default()
    {
        // setup
        Velocity vel;
        
        // Verify
        assert(vel.getDx() == 0.0);
        assert(vel.getDy() == 0.0);
        
    
    };
    void test_Velocity_NonDefault()
    {
        // Setup
        Velocity vel(20,30);
        
        
        // Verify
        assert(vel.getDx() == 20);
        assert(vel.getDy() == 30);
        

    };
    
    void test_Velocity_AddDx()
    {
        // setup
        Velocity vel(10.0,7.0);
        
        // exercise
        vel.addDx(-2.0);
        
        // verify
        assert(vel.getDx() == 8.0);
        
    
        
        
    };
    
    void test_Velocity_AddDy()
    {
        // setup
        Velocity vel(2.0,12.0);
        
        // exercise
        vel.addDY(12.0);
        
        // verify
        assert(vel.getDy() == 24.0);
    
        
    };
    
    void test_Velocity_SetDX()
    {
        // setup
        Velocity vel;
        
        // exercise
        vel.setDx(18.00);
        
        // verify
        assert(vel.getDx() == 18.00);
 
        
        
    };
    
    void test_Velocity_SetDY()
    {
        // setup
        Velocity vel;
        
        // exercise
        vel.setDy(18.00);
        
        // verify
        assert(vel.getDy() == 18.00);

        
    };
};




