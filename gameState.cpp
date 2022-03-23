
#include "gameState.h"


void GameState::gameStateTickProgression()
{

    if (ground.hitTarget(this->getProjectile()->getCurrentPointLocation()))
    {
        cout << " YOU WIN!" << endl;
        return;
    }

    /* Check if the projecile is below the minimum elevationof the ground. if it is below the ground elevation then you loose*/
    if (ground.getElevationMeters(this->getProjectile()->getCurrentPointLocation()) > this->getProjectile()->getCurrentLocationY())
    {
        cout << "YOU LOSE  :(" << endl;
        return;
    }


    this->advanceTimer();
    this->getProjectile()->applyPhysics();
    this->getProjectile()->refreshProjectileTail();


};




void GameState::displayScreen()
{
    
    ogstream gout(Position(5000.0, 18000));


    gout.setf(ios::fixed | ios::showpoint);
    gout.precision(1);
    gout << "Hang Time: "
        << this->getTimer() << "s";
    gout << "\tAltitude: "
        << this->getProjectile()->getCurrentLocationY() << " meters";
    gout << "\tSpeed: "
        << this->getProjectile()->getVelocityInstance().getSpeed() << " m/s";
    gout << "\tDistance: "
        << (this->getProjectile()->getCurrentLocationX() - this->getptHowitzer().getMetersX()) << " meters\n";
    gout << "\tHowitzer Angle: "
        << (this->getLaunchAngle() * (180 / 3.1415927)) << " Degrees";





    // draw the ground first
    this->getGround().draw(gout);

    // draw the howitzer
    gout.drawHowitzer(this->getptHowitzer(), this->getLaunchAngle(), this->getTimer());


    // draw the projectile
    for (int i = 0; i <20; i++)
    {  
            gout.drawProjectile(this->getProjectile()->getProjectileTail(i), i *.5);        
    }


}








