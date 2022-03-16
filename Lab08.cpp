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
using namespace std;

/*************************************************************************
 * GameState
 *************************************************************************/
//class GameState
//{
//public:
//   GameState(Position ptUpperRight) :
//      ptUpperRight(ptUpperRight),
//      ground(ptUpperRight),
//      time(0.0),
//      angle(0.0)
//   {
//      ptHowitzer.setPixelsX(Position(ptUpperRight).getPixelsX() / 2.0);
//      ptHowitzer.setPixelsY(Position(ptUpperRight).getPixelsY() / 4.0  );
//
//      ground.reset(ptHowitzer);
//
//      for (int i = 0; i < 20; i++)
//      {
//
//         projectilePath[i].setPixelsX((double)i * 2.0);
//         projectilePath[i].setPixelsY((double)i * 2.0);
//
//         projectilePath[i].setPixelsY(ptUpperRight.getPixelsY() / 1.5);
//
//      }
//   }
//
//   Ground ground;                 // the ground
//   Position  projectilePath[20];  // path of the projectile
//   Position  ptHowitzer;          // location of the howitzer
//   Position  ptUpperRight;        // size of the screen
//   double angle;                  // angle of the howitzer 
//   double time;                   // amount of time since the last firing
//};


class GameState
{
public:
    GameState(Position ptUpperRight) :
        ptUpperRight(ptUpperRight),
        ground(ptUpperRight),
        time(0.0),
        angle(0.0)
    {
        ptHowitzer.setPixelsX(Position(ptUpperRight).getPixelsX() / 2.0);
        ptHowitzer.setPixelsY(Position(ptUpperRight).getPixelsY() / 4.0);

        ground.reset(ptHowitzer);
        


        for (int i = 0; i < 20; i++)
        {
                  {       
                     projectilePath[i].setPixelsX((double)i * 2.0);
                     projectilePath[i].setPixelsY((double)i * 2.0);
            
                     projectilePath[i].setPixelsY(ptUpperRight.getPixelsY() / 1.5);

                  }
        }
    }
// the ground



    double angle;
    double time;                   // amount of time since the last firing









    Position  projectilePath[20];  // path of the projectile



    Projectile *getProjectile() { return projectileInstance; }
    Ground getGround() { return ground; }
    Position getptHowitzer() { return ptHowitzer;  }
    Position getptUpperRight() { return ptUpperRight;  }

    double getLaunchAngle() { return launchAngle; }
    void addLaunchAngle() { this->launchAngle += 0.05; }       
    void subtractLaunchAngle() { this->launchAngle -= 0.05; }    // angle of the howitzer };



private:

    Projectile *projectileInstance = new Projectile();
    Position  ptHowitzer;          // location of the howitzer
    Position  ptUpperRight;        // size of the screen
    Ground ground;
    double launchAngle;                  // angle of the howitzer 


};







/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/


bool startSim = false; // inilize sim outside loop.
bool tempLaunchPRohectile = false;
double howX = 0;
double howY = 0;

void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   GameState* pGameSate = (GameState*)p;

   


   //
   // accept input
   //

   // move a large amount
   if (pUI->isRight())
       //pGameSate->addLaunchAngle();
      pGameSate->angle += 0.05;
   if (pUI->isLeft())
       //pGameSate->subtractLaunchAngle();
      pGameSate->angle -= 0.05;

   // move by a little
   if (pUI->isUp())
      pGameSate->angle += (pGameSate->angle >= 0 ? -0.003 : 0.003);
   if (pUI->isDown())
      pGameSate->angle += (pGameSate->angle >= 0 ? 0.003 : -0.003);

   // fire that gun
   if (pUI->isSpace())
   {
       pGameSate->time = 0.0;
       startSim = true;
   }


   //
   // perform all the game logic
   //



   // advance time by half a second.
   pGameSate->time += 0.5;






   // move the projectile across the screen

   pGameSate->projectilePath->setMetersY(pGameSate->getProjectile()->getCurrentLocationY());
   pGameSate->projectilePath->setMetersX(pGameSate->getProjectile()->getCurrentLocationX());


   if (startSim == true)
   {
       //pGameSate->projectilePath->setPixelsX(pGameSate->getptHowitzer().getMetersX());
       //pGameSate->projectilePath->setPixelsY(pGameSate->getptHowitzer().getMetersY());

       howX = pGameSate->getptHowitzer().getMetersX();
       howY = pGameSate->getptHowitzer().getMetersY();
       cout << pGameSate->getptHowitzer().getMetersY();

       pGameSate->getProjectile()->setCurrentLocationX(howX);
       pGameSate->getProjectile()->setCurrentLocationY(howY);


       pGameSate->getProjectile()->applyLaunchPhysics(pGameSate->angle);

       startSim = false;
       tempLaunchPRohectile = true;



       cout << "Sim has started" << endl;
   }





   if (tempLaunchPRohectile == true)
   {
       pGameSate->getProjectile()->applyPhysics();
       pGameSate->getProjectile()->noDDestroy();
   }









   for (int i = 0; i < 20; i++)
   {
       double x = pGameSate->projectilePath->getPixelsX();
       double y = pGameSate->projectilePath->getPixelsY();
       //x -= .5;
       //y += .5;



       if (x < 0)
       {
           x = pGameSate->getptUpperRight().getPixelsX();
           y = pGameSate->getptUpperRight().getPixelsY();

       }
   }




   //
   // draw everything
   //

   ogstream gout(Position(10.0, pGameSate->getptUpperRight().getPixelsY() - 20.0));

   // draw the ground first
   pGameSate->getGround().draw(gout);

   // draw the howitzer
   gout.drawHowitzer(pGameSate->getptHowitzer(), pGameSate->angle, pGameSate->time);

   // draw the projectile
   for (int i = 0; i < 20; i++)
      gout.drawProjectile(pGameSate->projectilePath[i], 0.5 * (double)i);

   // draw some text on the screen
   gout.setf(ios::fixed | ios::showpoint);
   gout.precision(1);
   gout << "Time since the bullet was fired: "
      << pGameSate->time << "s\n";
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
