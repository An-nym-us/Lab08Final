#pragma once
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
    {
        setDx(getDx() + dx);
    }
    
    double addDy(double dy)
    {
        setDy(getDy() + dy);;
    }
    
    void reverse()
    {
        dx *= -1.0;
        dy *= -1.0;
    }
private:
    double dx;
    double dy;
}
