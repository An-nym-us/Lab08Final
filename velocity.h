#pragma once

#include <iostream>

using namespace std;
/*********************************************
 * Velocity
 *
 *********************************************/


// Change in Position per unit Time
class Velocity
{
    
public:
    Velocity() :dx(0.0), dy(0.0);
    double getDx()
    {
        return this -> dx;
    }
    double getDy()
    {
        return this -> dy;
    }
    
    double getSpeed();
    
    void setDx(double dx)
    {
        this -> dx = dx;
    }
    
    void setDy(double dy)
    {
        this -> dy = dy;
    }
    
    double setSpeed();
    
    void addDx(double dx)



    Velocity() : dx(0.0), dy(0.0) {}
    Velocity(double dx, double dy);

    // getters
    double getDx() const { return dx; }

    double getDy() const { return dy; }

    // Setters

    void setDx(double dx)
    {
        setDx(getDx() + dx);
    }

    void  setDy(double dy)
    {
        this->dy = dy;
    }

    void addDx(double addDx) {
        setDx(getDx() + addDx);
    }

    void addDY(double addDy)
    
    void reverse()
    {
        dx *= -1.0;
        dy *= -1.0;
    }



private:
    double dx;
    double dy;

};
