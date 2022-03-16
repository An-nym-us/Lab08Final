#pragma once
#include "position.h"
#include <vector>
#include "uiDraw.h"

class Projectile
{
public:
    Projectile();
    void advance(double time);
    void draw(ogstream &gout) const;
    bool flying();
    double getAltitude();
    double getFlightTime();
    double getFlightDistance();
    double getSpeed();
    double getCurrentTime();
    void setMass(double mass)
    {
        this -> mass = mass;
    }
    void setRadious(double radious)
    {
        this -> radious = radious;
    }
    
private:
    double mass;
    double radious;
    vector<int> flightPath;
}
