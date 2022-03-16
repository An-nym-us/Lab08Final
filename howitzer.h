#pragma once

#include "position.h"
#include "uiDraw.h"

class Howitzer
{
public:
    Howitzer();
    // Get the Position of the Howitzer
    void getPosition();
    void generatePosition();
    
    double getMuzzleVelocity()
    {
        return this-> muzzleVelocity;
    };
    void setMuzzleVelocity(double velocity)
    {
        this -> muzzleVelocity = velocity;
    }
    // Rotate the Howitzer
    void rotate(double radians);
    
    // Raise the Howitzer
    void raise(double radians);
    
    // Draw the Howitzer on the Screen
    void draw(ogstream &gout) const;
private:
    Position post;
    double muzzleVelocity;
}
