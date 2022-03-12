/***********************************************************************
 * Source File:
 *    Point : The representation of a velocty on the screen
 * Author:
 *         Jonathan Gunderson and Sulav Dahal
 * Summary:
 *    Everything we need to know about a velocity
 ************************************************************************/
#include "velocity.h"



Velocity::Velocity(double dx, double dy): dx(0.0), dy(0.0)
{
    setDx(dx);
    setDy(dy);
}
