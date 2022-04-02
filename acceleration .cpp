
/***********************************************************************
 * Source File:
 *    Point : The representation of a Acceleration on the screen
 * Author:
 *         Jonathan Gunderson and Sulav Dahal
 * Summary:
 *    Everything we need to know about a Acceleration
 ************************************************************************/
#include "acceleration.h"




 /*****************************************************************
 *
 *
 *****************************************************************/
Acceleration::Acceleration(double dx, double dy) : ddx(0.0), ddy(0.0)
{
    setDDx(ddx);
    setDDy(ddy);
}