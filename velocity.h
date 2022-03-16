//
//  velocity.h
//  Lab08
//
//  Created by Sulav Dahal on 3/4/22.
//

#pragma once

#include <iostream>

using namespace std;
/*********************************************
 * Velocity
 *
 *********************************************/


class Velocity
{
    
public:



    Velocity() : dx(0.0), dy(0.0) {}
    Velocity(double dx, double dy);

    // getters
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



private:
    double dx;
    double dy;

};
