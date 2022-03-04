#include "environment.h"



//Testing the testing system case 1
int Environment::error_checking_1(int data)
{
	return data * changethis;
}


double Environment:: interpolation_check(double d0, double r0, double d1, double r1, double d)
{
    double range = r0 + (r1-r0) * (d-d0) / (d1 -d0);
    return range;
}
