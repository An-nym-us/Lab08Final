/***********************************************************************
 * Source File:
 *    Ground : Represents the ground in the artillery simulation
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Where the ground is located and where the target is drawn
 ************************************************************************/

#include "ground.h"   // for the Ground class definition
#include "uiDraw.h"   // for random() and drawLine()
#include <cassert>


using namespace std;
const int WIDTH_HOWITZER = 14;

const double MIN_ALTITUDE = 300.0;  // min altitude is at 984'
const double MAX_ALTITUDE = 3000.0; // max altitude is 3,000m or 9842.52ft
const double MAX_SLOPE = 1.0; // steapness of the features. Smaller number is flatter
const double LUMPINESS = 0.15; // size of the hills. Smaller number is bigger features
const double TEXTURE = 3.0;   // size of the small features such as rocks

Ground::Ground(const Position & posUpperRight) :
   posUpperRight(posUpperRight),
   iHowitzer(0),
   ground(NULL)
{
   // allocate the array
   ground = new double[(int)posUpperRight.getPixelsX()];
}

/************************************************************************
 * RESET
 * Create a new ground
 ************************************************************************/
 void Ground :: reset(Position & posHowitzer)
 {
   // remember the integer width for later. It will come in handy
   int width = (int)posUpperRight.getPixelsX();
   assert(width > 0);

   // determine the location of the target
   iHowitzer = (int)(posHowitzer.getPixelsX());
   if (iHowitzer > width / 2)
      posTarget.setPixelsX(random((int)(width * 0.05), (int)(width * 0.45)));
   else
      posTarget.setPixelsX(random((int)(width * 0.55), (int)(width * 0.95)));
   assert(iHowitzer >= 0 && iHowitzer < width);

   // determine the maximum and minimum altitude
   Position posMinimum(0.0, MIN_ALTITUDE);
   Position posMaximum(posUpperRight.getMetersX(), MAX_ALTITUDE);

   // give each location on the ground an elevation
   ground[0] = posMinimum.getPixelsY(); // the initial elevation is low
   double dy = MAX_SLOPE / 2.0;  // the initial slope is heavily biased to up
   for (int i = 1; i < width; i++)
   {
      // put the howitzer on flat ground
      if (i > iHowitzer - WIDTH_HOWITZER / 2 &&
         i < iHowitzer + WIDTH_HOWITZER / 2)
      {
         ground[i] = ground[i - 1];
      }
      else
      { 
         // what percentage of the elevation were we at?
         double percent = (ground[i - 1] - posMinimum.getPixelsY()) /
                          (posMaximum.getPixelsY() - posMinimum.getPixelsY());

         // set the slope of the ground
         dy += (1.0 - percent) * random(0.0, LUMPINESS) +
               (percent) * random(-LUMPINESS, 0.0);
         if (dy > MAX_SLOPE)
            dy = MAX_SLOPE;
         if (dy < -MAX_SLOPE)
            dy = -MAX_SLOPE;

         // determine the elevation according to the slope
         ground[i] = ground[i - 1] + dy + random(-TEXTURE, TEXTURE);
      }
   }

   // Place the target on top of the ground
   assert((int)posTarget.getPixelsX() >= 0 && (int)posTarget.getPixelsX() < width);
   posTarget.setPixelsY(ground[(int)posTarget.getPixelsX()]);

   // set the howitzer's elevation
   posHowitzer.setPixelsY(ground[iHowitzer]);
}

/*****************************************************************
 * DRAW
 * Draw the ground on the screen
 ****************************************************************/
void Ground::draw(ogstream & gout) const
{
   // put the meter markers along the side
   for (Position pos(0.0, 1000.0); pos.getPixelsY() < posUpperRight.getPixelsY(); pos.addMetersY(1000.0))
   {
      Position posLeft(pos);
      Position posRight(pos);
      posRight.setPixelsX(posUpperRight.getPixelsX());
      gout.drawLine(posLeft, posRight, 0.85, 0.85, 0.85);
   }

   // iterate through the entire ground and draw it all
   int width = (int)posUpperRight.getPixelsX();
   for (int i = 0; i < width; i++)
   {
      Position posBottom;
      Position posTop;
      posBottom.setPixelsX((double)i);
      posTop.setPixelsX((double)(i+1));
      posTop.setPixelsY(ground[i]);
      gout.drawRectangle(posBottom, posTop, 0.6 /*red*/, 0.4 /*green*/, 0.2 /*blue*/);
   }

   // draw the target
   gout.drawTarget(posTarget);

   // put the kilometer markers along the bottom
   for (Position pos(1000.0, 0.0); pos.getPixelsX() < posUpperRight.getPixelsX(); pos.addMetersX(1000.0))
   {
      Position posBottom(pos);
      Position posTop(pos);
      posTop.addPixelsY(10);
      gout.drawLine(posTop, posBottom, 0.6, 0.6, 0.6);
   }

   // put the kilometer labels along the bottom
   for (Position pos(5000.0, 0.0); pos.getPixelsX() < posUpperRight.getPixelsX(); pos.addMetersX(5000.0))
   {
      Position posText(pos);
      posText.addPixelsY(15);
      posText.addPixelsX(-10);

      gout = posText;
      gout << (int)(pos.getMetersX() / 1000.0) << "km";
   }

   // draw the altitude labels along the side
   for (Position pos(0.0, 2000.0); pos.getPixelsY() < posUpperRight.getPixelsY(); pos.addMetersY(2000.0))
   {
      Position posText(pos);
      posText.addPixelsX(5);
      posText.addPixelsY(-2);

      gout = posText;
      gout << (int)(pos.getMetersY()) << "m";
   }

}




/************************************************************************
 * Game state check
 * Check if projectile has impacted the target cube
 ************************************************************************/
bool Ground:: hitTarget(const Position &ProjectilePosition)const
{
    /* This will see ofthe projectile is within a range of the width of the center of the cube */
    if (!  (((getTarget().getMetersX() - 200) < ProjectilePosition.getMetersX()) && ProjectilePosition.getMetersX() < getTarget().getMetersX() +200))
    {  
        return false;
    }

    /* This will see ifhte projectile is below the height of the cube */
    if (! (ProjectilePosition.getMetersY() < getTarget().getMetersY() ))
    {
        return false;
    }

    return true;
}

