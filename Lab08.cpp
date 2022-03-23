/*************************************************************
 * 1. Name:
 *      The Key
 * 2. Assignment Name:
 *      Lab 08: M777 Howitzer
 * 3. Assignment Description:
 *      Simulate firing the M777 howitzer 15mm artillery piece
 * 4. What was the hardest part? Be as specific as possible.
 *      ??
 * 5. How long did it take for you to complete the assignment?
 *      ??
 *****************************************************************/

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "ground.h"     // for GROUND
#include "position.h"   // for POINT
#include <iostream>
#include <cmath>
#include "projectile.h"
#include "gameState.h"
using namespace std;

/*************************************************************************
 * GameState
 *************************************************************************/
/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/




bool startSim = false; // inilize sim outside loop.
bool tempLaunchPRohectile = false;
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL.
    


   GameState* pGameStateInstance = (GameState*)p;


   //
   // accept input
   //

   // move a large amount
   if (pUI->isRight())
       //pGameStateInstance->addLaunchAngle();
      pGameStateInstance->angle += 0.03;
   if (pUI->isLeft())
       //pGameStateInstance->subtractLaunchAngle();
      pGameStateInstance->angle -= 0.03;

   // move by a little
   if (pUI->isUp())
      pGameStateInstance->angle += (pGameStateInstance->angle >= 0 ? -0.002 : 0.002);
   if (pUI->isDown())
      pGameStateInstance->angle += (pGameStateInstance->angle >= 0 ? 0.002 : -0.002);

   // fire that gun
   if (pUI->isSpace())
   {
       pGameStateInstance->time = 0.0;
       startSim = true;
       
   }


   //
   // perform all the game logic
   //


//    double targetLocation = pGameStateInstance -> getGround().getTarget().getMetersX();
//    double targetLocationY = pGameStateInstance -> getGround().getTarget().getMetersY();
//    double xPath = pGameStateInstance -> getProjectile() -> getCurrentLocationX();
//    double yPath = pGameStateInstance -> getProjectile() -> getCurrentLocationY();
    
    // advance time by half a second.

    pGameStateInstance->time += 0.5;
  
//    cout << targetLocation << " ," << targetLocationY<< " These are my paths::" << endl;
 
   // move the projectile across the screen
   if (startSim == true)
   {
    
       pGameStateInstance->getProjectile()->setCurrentLocationX(pGameStateInstance->getptHowitzer().getMetersX());
       pGameStateInstance->getProjectile()->setCurrentLocationY(pGameStateInstance->getptHowitzer().getMetersY());
       pGameStateInstance->getProjectile()->applyLaunchPhysics(pGameStateInstance->angle);
     
       startSim = false;
//       startSim = false; // Do this function once ssytem, this will need to get move into the game state class at some point
       tempLaunchPRohectile = true;
       cout << "Sim has started" << endl;
   }


   if (tempLaunchPRohectile == true)
   {
       pGameStateInstance->GameStateTickProgress();
<<<<<<< HEAD
}

//    for(int i=0; i < 20; i++){
//
////        cout << pGameStateInstance-> projectilePath[i].getPixelsX() << ", here" << pGameStateInstance-> projectilePath[i].getPixelsY() << endl;
//        double x = pGameStateInstance -> projectilePath[i].getPixelsX();
//        x-=1.0;
//        if (x <0)
//            x = pGameStateInstance-> getptHowitzer().getPixelsX();
//        pGameStateInstance-> projectilePath[i].setPixelsX(x);
//    }
//    for(int i=0; i < 20; i++)
//    {
//        double x = pGameStateInstance -> projectilePath->getPixelsX();
//        double y = pGameStateInstance->projectilePath->getPixelsY();
//        pGameStateInstance-> projectilePath[i].setPixelsX(x);
//        pGameStateInstance-> projectilePath[i].setPixelsY(y);
//    }
=======
   }

//    if((xPath>=0 && xPath == targetLocation) && (yPath>=0 && yPath == targetLocationY))
//    {
//        exit(0);
//    }
    
>>>>>>> parent of d297ffc (877)

   //
   // draw everything
   //

   ogstream gout(Position(10.0, pGameStateInstance->getptUpperRight().getPixelsY() - 20.0));

   // draw the ground first
   pGameStateInstance->getGround().draw(gout);

   // draw the howitzer
   gout.drawHowitzer(pGameStateInstance->getptHowitzer(), pGameStateInstance->angle, pGameStateInstance->time);

   // draw the projectile
   for (int i = 0; i < 20; i++)
   {
       cout << pGameStateInstance-> projectilePath[i] << endl;
      gout.drawProjectile(pGameStateInstance->projectilePath[i], 0.5 * (double)i);

<<<<<<< HEAD
   }

   // draw some text on the screen
    pGameStateInstance -> onScreenStats();
  


}


void GameState:: onScreenStats()
{
    ogstream gout;
    gout.setf(ios::fixed | ios::showpoint);
    gout.precision(1);
    gout.setPosition(Position(18000.0,18000.0));
    
    double distance =this->getProjectile()->getCurrentLocationX() - this->getptHowitzer().getMetersX();
    gout << "Hang Time: "
     << this->getTimer() << "s" << endl;
    gout << "\tAltitude: "
     << this->getProjectile()->getCurrentLocationY() << " meters" << endl;
    gout << "\tSpeed: "
     << this->getProjectile()->getVelocityInstance().getSpeed() << " m/s" << endl;
    gout << "\tDistance: "
     <<  (distance < 0.0 ? 0.0 : distance) << " meters" << endl;
    gout << "\tHowitzer Angle: "
     << (this->angle * (180 / 3.1415927)) << " Degrees" << endl;
=======
   // draw some text on the screen
   gout.setf(ios::fixed | ios::showpoint);
   gout.precision(1);
   gout << "Time since the bullet was fired: "
      << pGameStateInstance->time << "s\n";
>>>>>>> parent of d297ffc (877)
}



double Position::metersFromPixels = 40.0;



/*********************************
 * Initialize the simulation and set it in motion
 *********************************/



#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32




int main(int argc, char** argv)
#endif // !_WIN32
{
   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setPixelsX(700.0);
   ptUpperRight.setPixelsY(500.0);
   Position().setZoom(40.0 /* 42 meters equals 1 pixel */);
   Interface ui(0, NULL,
      "Demo",   /* name on the window */
      ptUpperRight);

   // Initialize the demo
   GameState demo(ptUpperRight);

   // set everything into action
   ui.run(callBack, &demo);


   return 0;
}
