#pragma once


#include <iostream>
using namespace std;



class Acceleration
{
public:



    Acceleration() : ddx(0.0), ddy(0.0) {}
    Acceleration(double ddx, double ddy);

    // getters
    double getDDx() const { return ddx; }

    double getDDy() const { return ddy; }

    // Setters

    void setDDx(double ddx)
    {
        this->ddx = ddx;
    }

    void  setDDy(double ddy)
    {
        this->ddy = ddy;
    }

    void addDDx(double addDDx) {
        setDDx(getDDx() + addDDx);
    }

    void addDDY(double addDDy)
    {
        setDDy(getDDy() + addDDy);
    }
private:
    double ddx;
    double ddy;
};