#pragma once






class Environment
{
	friend class TestEnvironment;




public:	
	//Testing the testing system case 1
	int error_checking_1(int data);
    
    double interpolation_check(double d0,double r0, double d1, double r1, double d);


private:

	int changethis = 0;

};
