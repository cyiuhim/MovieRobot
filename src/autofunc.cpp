#include "vex.h"
#include "auto.h"

double originaly, originalx, xvelocity, yvelocity, xgoal, ygoal;
double speedconst = 2.5;
double pi = 3.14159265358979;
int moveno;

void move(double xcoor, double ycoor, double movetime) //move to a point on coordinates with the arm
{
  originalx = xmotor.position(deg);
  originaly = ymotor.position(deg);
  xvelocity = (xcoor - originalx) / (speedconst * movetime);
  yvelocity = (ycoor - originaly) / (speedconst * movetime);
  ymotor.startRotateTo(ycoor, deg, yvelocity, rpm);
  yright.startRotateTo(ycoor, deg, yvelocity, rpm);
  xmotor.rotateTo(xcoor, deg, xvelocity, rpm);
}
void penup()
{
  Brain.Timer.reset();
  while(Brain.Timer.value() < 0.14)
  {
    intake.spin(forward, 50, vex::percentUnits::pct);
  }
  intake.stop();
}
void pendown(double time)
{
  Brain.Timer.reset();
  while(Brain.Timer.value() < time)
  {
    intake.spin(reverse, 40, vex::percentUnits::pct);
  }
  intake.stop();
}
void drawarc(int direction, int startdeg, int enddeg, double xcentre, double ycentre, int increment, double radius)
//draws an arc, by plotting tightly packed points on the arc, used for letters C, O and D
//1 = counterclockwise, 2 = clockwise
{ 
  switch(direction)
  {
    case 1: 
    moveno = (enddeg - startdeg) / increment;
    for(int i = 1; i <= moveno; i++)
    {
      xgoal = xcentre + radius * cos((startdeg + increment * i) * pi / 180);
      ygoal = ycentre + radius * sin((startdeg + increment * i) * pi / 180);
      move(xgoal, ygoal, 0.06);
    }
    break;
    case 2:
    moveno = (startdeg - enddeg) / increment;
    for(int i = 1; i <= moveno; i++)
    {
      xgoal = xcentre + radius * cos((startdeg - increment * i) * pi / 180);
      ygoal = ycentre + radius * sin((startdeg - increment * i) * pi / 180);
      move(xgoal, ygoal, 0.06);
    }
    break;
    default:
    xmotor.stop();
    ymotor.stop();
    break;
  }
}