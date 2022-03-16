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


    double getSpeed();
    

    double setSpeed();
    





    

  





    //void addDx(double addDx) {
    //    setDx(getDx() + addDx);
    //}

    //void addDY(double addDy)
    //{
    //    setDy(getDy() + addDy);
    //}
    //
    //void reverse()
    //{
    //    dx *= -1.0;
    //    dy *= -1.0;
    //}



private:
    double dx;
    double dy;

};
