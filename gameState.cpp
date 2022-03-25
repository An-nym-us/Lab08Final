#include "gameState.h"



/*************************************************************************
 *
 *
 *************************************************************************/
//GameState::GameState(Position ptUpperRight)
//    :ptUpperRight(ptUpperRight),    ground(ptUpperRight),    time(7.77)
//{
//
//    isSimulationActive = false;
//    simulationPreFlightcheck = false;
//}



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

    if (ground.hitTarget(this->getProjectile()->getCurrentPointLocation()))
    {
        gout << "Target Hit!!!";
        this->deactivateSimulation();
        return;
    }

    /* Check if the projecile is below the minimum elevationof the ground. if it is below the ground elevation then you lose*/
    if (ground.getElevationMeters(this->getProjectile()->getCurrentPointLocation()) > this->getProjectile()->getLocationY())
    {
        gout << "Target Missed";
        this->deactivateSimulation();
        return;
    }
}


/*************************************************************************
 * Fire any pre flight simualtion like settign pre-flight launch information
 *************************************************************************/
//void GameState::activatePreFlightCheck() 
//{ 
//    resetTimer();
//    this->getProjectile()->initializeProjectileLaunchState(this->getLaunchAngle(), this->getHowitzer());
//    simulationPreFlightcheck = true; 
//}




/*************************************************************************
 *
 *
 *************************************************************************/
void GameState::displayScreen()
{
    ogstream gout(Position(21000.0, 19000));


    //gout.setf(ios::fixed | ios::showpoint);
    //gout.precision(1);
    //gout << "Hang Time: "
    //    << this->getTimer() << "s\n";
    //gout << "Altitude: "
    //    << this->getProjectile()->getLocationY() << " meters\n";
    //gout << "Speed: "
    //    << this->getProjectile()->getVelocityInstance().getSpeed() << " m/s\n";
    //gout << "Distance: "
    //    << (this->getProjectile()->getLocationX() - this->getHowitzer().getMetersX()) << " meters\n";
    //gout << "Howitzer Angle: "
    //    << (this->getLaunchAngle() * (180 / 3.1415927)) << " Degrees";


    /* draw win/lose text */
    this->gameStateProjectileStatus();

    // draw the ground first
    this->getGround().draw(gout);

    // draw the howitzer
    gout.drawHowitzer(this->getHowitzer()->getptHowitzer(), this->getHowitzer()->getLaunchAngle(), this->getTimer());


    // draw the projectile
    for (int i = 0; i <20; i++)
    {  
        gout.drawProjectile(this->getProjectile()->getProjectileTail(i), i *.5);        
    }


}








