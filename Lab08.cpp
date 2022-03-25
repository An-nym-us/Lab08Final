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
















/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/



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
       pGameStateInstance->getHowitzer()->advanceLaunchAngleFullStep();
   if (pUI->isLeft())
       pGameStateInstance->getHowitzer()->decrementLaunchAngleFullStep();

   // move by a little
   if (pUI->isUp())
       pGameStateInstance->getHowitzer()->advanceLaunchAngleHalfStep();
   if (pUI->isDown())
       pGameStateInstance->getHowitzer()->decrementLaunchAngleHalfStep();

   // fire that gun
   if (pUI->isSpace())
   {
       pGameStateInstance->activatePreFlightCheck();
   }




   if (pGameStateInstance->isPreFlightCheckComplete())
   {
       pGameStateInstance->deactivatePreFlightCheck();
       pGameStateInstance->activateSimulation();
   }


   if (pGameStateInstance->isSimActive())
   {
       pGameStateInstance->activeSimulationTickProgression();
   }


   pGameStateInstance->displayScreen();

 




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
