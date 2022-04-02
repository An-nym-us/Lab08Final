#include "gameState.h"



/*************************************************************************
 *
 *
 *************************************************************************/
GameState::GameState(Position ptUpperRight)
    :ptUpperRight(ptUpperRight), time(7.77)
{
    simulationPreFlightcheck = false;
    howitzerInstance = new Howitzer(ptUpperRight);
    projectileInstance = new Projectile(howitzerInstance->getMuzzleVelocity());
    isSimulationActive = false;

}



/*************************************************************************
 *
 *
 *************************************************************************/
void GameState::activeSimulationTickProgression()
{
    this->advanceTimer();
    this->getProjectile()->applyPhysics();
    this->getProjectile()->refreshProjectileTail();
}


/*************************************************************************
 *
 *
 *************************************************************************/
void GameState::gameStateProjectileStatus()
{
    ogstream gout(Position(10000.0, 10000));

    if (this->getHowitzer()->getGround().hitTarget(*this->getProjectile()->getCurrentPointLocation()))
    {
        gout << "Target Hit!!!";
        this->deactivateSimulation();
        return;
    }

    /* Check if the projecile is below the minimum elevationof the ground. if it is below the ground elevation then you lose*/
    if (this->getHowitzer()->getGround().getElevationMeters(*this->getProjectile()->getCurrentPointLocation()) > this->getProjectile()->getCurrentPointLocation()->getMetersY())
    {
        gout << "Target Missed";
        this->deactivateSimulation();
        return;
    }
}


/*************************************************************************
 * Fire any pre flight simualtion like settign pre-flight launch information
 *************************************************************************/
void GameState::activatePreFlightCheck()
{
    resetTimer();
    this->getProjectile()->initializeProjectileLaunchState(this->getHowitzer()->getLaunchAngle(), this->getHowitzer()->getptHowitzer());
    simulationPreFlightcheck = true;
}




/*************************************************************************
 *
 *
 *************************************************************************/
void GameState::displayScreen()
{
    ogstream gout(Position(21000.0, 19000));


    gout.setf(ios::fixed | ios::showpoint);
    gout.precision(1);
    gout << "Hang Time: "
        << this->getTimer() << "s\n";
    gout << "Altitude: "
        << this->getProjectile()->getCurrentPointLocation()->getMetersY() << " meters\n";
    gout << "Speed: "
        << this->getProjectile()->getVelocityInstance().getSpeed() << " m/s\n";
    gout << "Distance: "
        <<  abs((this->getProjectile()->getCurrentPointLocation()->getMetersX() - this->getHowitzer()->getptHowitzer().getMetersX())) << " meters\n";
    gout << "Howitzer Angle: "
        << (this->getHowitzer()->getLaunchAngle() * (180 / 3.1415927)) << " Degrees";


    /* draw win/lose text */
    this->gameStateProjectileStatus();

    // draw the ground first
    
    this->getHowitzer()->getGround().draw(gout);

    
    // draw the howitzer
    gout.drawHowitzer(this->getHowitzer()->getptHowitzer(), this->getHowitzer()->getLaunchAngle(), this->getTimer());


    // draw the projectile
    for (int i = 0; i <20; i++)
    {  
       gout.drawProjectile(this->getProjectile()->getProjectileTail(i), i *.5);        
    }


}








