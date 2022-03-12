/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/

#include "test.h"
#include "testPosition.h"
#include "testEnvironment.h"
#include "testEnvironmentalConstants.h"
#include "testVelocity.h"
#include "environmentalConstants.h"
#include <iostream>

/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
int main()
{
	testRunner();
}




void testRunner()
{

	TestPosition().run();
	TestEnvironment().run();
	TestEnvironmentalConstants().run();
    //TestVelocity().run();
    

}
