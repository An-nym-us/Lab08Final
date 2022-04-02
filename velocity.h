/***********************************************************************
 * Source File:
 *    Point : The representation of a velocty on the screen
 * Author:
 *         Jonathan Gunderson and Sulav Dahal
 * Summary:
 *    Everything we need to know about a velocity
 ************************************************************************/
#pragma once

#include <iostream>
#include <cmath>

using namespace std;
/*********************************************
 * Velocity
 *
 *********************************************/


// Change in Position per unit Time
class Velocity
{
    
public:
    Velocity() :dx(0.0), dy(0.0) {}
    Velocity(double dx, double dy);



    

    double getDx() const { return dx; }

    double getDy() const { return dy; }

    // Setters

    void setDx(double dx)
    {
        this->dx = dx;
    }

    void  setDy(double dy)
    {
        this->dy = dy;
    }

    void addDx(double addDx) {
        setDx(getDx() + addDx);
    }

    void addDY(double addDy)
    {
        setDy(getDy() + addDy);
    }


    double getSpeed() { 
       return sqrt(dx * dx + dy * dy); }
    

private:
    double dx;
    double dy;

};
