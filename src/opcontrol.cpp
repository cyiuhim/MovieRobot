#include "vex.h"
#include "opcontrol.h"

double margin = 10;
double yl, yr;
int stickcontrol;
int up, down, l1, l2, xmode, ymode, automode, zmove, bmode, bpresstime, btime;
double xoffset, yoffset, xoriginal, yoriginal, xtarget, ytarget, frontspeed, turnspeed,  leftspeed, rightspeed, xspeed, yspeed;
int zpressed, intakepressed;
int bbutton[2];
int benable = 0;
void drive()
{ 
  if(abs(Controller1.Axis4.value()) > margin)
  {
    turnspeed = Controller1.Axis4.value();
  }
  else
  {
    turnspeed = 0;
  }
  if(abs(Controller1.Axis3.value()) > margin)
  {
    frontspeed = Controller1.Axis3.value();
  }
  else
  {
    frontspeed = 0;
  }
  if(benable == 1)
  {
    leftspeed = 0.5 * frontspeed + 0.45 * turnspeed;
    rightspeed = 0.5 * frontspeed - 0.7 * turnspeed;
  }
  else
  {
    leftspeed = 0.3 * frontspeed + 0.15 * turnspeed;
    rightspeed = 0.3 * frontspeed - 0.4 * turnspeed;
  }
  leftdrive.spin(fwd, leftspeed, vex::percentUnits::pct);
  rightdrive.spin(fwd, rightspeed, vex::percentUnits::pct);
}
void ycontrol()
{
  up = 0;
  down = 0;
  if(benable == 1)
  {
    yspeed = 50;
  }
  else
  {
    yspeed = 30;
  }
  if(Controller1.ButtonUp.pressing())
  {
    up = 1;
    ymode = 1;
  }
  else if(Controller1.ButtonDown.pressing())
  {
    down = 1;
    ymode = 2;
    
  }
  else
  {
    ymode = 3;
    ymotor.stop();
    yright.stop();
  }
}
void xcontrol()
{
  if(benable == 1)
  {
    xspeed = 50;
  }
  else
  {
    xspeed = 30;
  }
  if(Controller1.ButtonLeft.pressing())
  {
    xmode = 1;
  }
  else if(Controller1.ButtonRight.pressing())
  {
    xmode = 2;
       
  }
  else
  {
    xmode = 3;
  }
}
void stickmove()
{
  if(xmode == 1 && abs(Controller1.Axis1.value()) < 2)
  {
    if(xmotor.position(deg) > -340)
    {
    xmotor.spin(reverse, xspeed, vex::percentUnits::pct);
    }
    else
    {
      xmotor.stop();
    }
    xoriginal = xmotor.position(deg);
  }
  if(xmode == 2 && abs(Controller1.Axis1.value()) < 2)
  {
     if(xmotor.position(deg) < 240)
    {
    xmotor.spin(forward, xspeed, vex::percentUnits::pct);
    }
    else
    {
      xmotor.stop();
    }
    xoriginal = xmotor.position(deg);
  } 
  if(ymode == 1 && abs(Controller1.Axis2.value()) < 2)
  {
    if(ymotor.position(deg) < 430)
    {
    ymotor.spin(fwd, yspeed, vex::percentUnits::pct);
    yright.spin(fwd, yspeed, vex::percentUnits::pct);
    }
    else
    {
      ymotor.stop();
      yright.stop();
    }
    stickcontrol = 0;
    yl = ymotor.position(deg);
    yr = ymotor.position(deg);
    yoriginal = ymotor.position(deg);
  }
  if(ymode == 2 && abs(Controller1.Axis2.value()) < 2)
  {
    down = 1;
    if(ymotor.position(deg) > 190)
    {
    ymotor.spin(reverse, yspeed, vex::percentUnits::pct);
    yright.spin(reverse, yspeed, vex::percentUnits::pct);
    }
    else
    {
      ymotor.stop();
      yright.stop();
    }
    yoriginal = ymotor.position(deg);
        yl = ymotor.position(deg);
    yr = ymotor.position(deg);
    stickcontrol = 0;
  }
  xtarget = xoriginal + xoffset;
  ytarget = yoriginal + yoffset;
  if(xmode == 3 && ymode == 3)
  {
    while(fabs(ymotor.position(degrees) - ytarget) > 2 || fabs(xmotor.position(degrees)-xtarget) > 2)
    {
    ymotor.startRotateTo(ytarget, deg, 40, rpm);
    yright.startRotateTo(ytarget, deg, 40, rpm);
    xmotor.startRotateTo(xtarget, deg, 40, rpm);
    wait(5, msec);
    }  
  }
}
void zcontrol()
{
  l1 = 0;
  l2 = 0;
  if(Controller1.ButtonL1.pressing())
  {
    zmotor.spin(forward, 40, vex::percentUnits::pct);
    l1 = 1;
  }
  else if(Controller1.ButtonL2.pressing())
  {
    zmotor.spin(reverse, 15, vex::percentUnits::pct);
    l2 = 1;
  }
  else
  {
    zmotor.stop();
  }
}
int zcontrol1()
{
  l1 = 0;
  l2 = 0;
  if(Controller1.ButtonL1.pressing())
  {
    return 1;
  }
  else if(Controller1.ButtonL2.pressing())
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void intakecontrol()
{
  if(Controller1.ButtonR1.pressing())//down
  {
    intake.spin(reverse, 60, vex::percentUnits::pct);
  }
  else if(Controller1.ButtonR2.pressing())//up
  {
    intake.spin(forward, 50, vex::percentUnits::pct);
  }
  else
  {
    intake.stop();
  }
}

int intakecontrol1()
{
  if(Controller1.ButtonR1.pressing())//down
  {
    return 1;
  }
  else if(Controller1.ButtonR2.pressing())//up
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
void opcontrol()
{ 

    stickcontrol = 1;
    yoffset = Controller1.Axis2.value();
    xoffset = Controller1.Axis1.value();
    drive();
    ycontrol();
    xcontrol();
    stickmove();
    /*
    Brain.Screen.setCursor(1,1);
    Brain.Screen.print(zpressed);
    Brain.Screen.setCursor(2,1);
    Brain.Screen.print(intakepressed);
    Brain.Screen.setCursor(3,1);
    Brain.Screen.print(bbutton[0]);
    Brain.Screen.setCursor(4,1);
    Brain.Screen.print(bbutton[1]);
    Brain.Screen.setCursor(5,1);
    Brain.Screen.print(bpresstime);
    */
}

void bcontrol()
{
  opcontrol();
  zpressed = zcontrol1();
  intakepressed = intakecontrol1();
  if(benable == 1)
  {
    bbutton[1] = bbutton[0];
    if(Controller1.ButtonB.pressing())
    {
      bbutton[0] = 1;
      if(zpressed == 0 && intakepressed == 0)
      {
        bpresstime += 10;
      }
    }
    else
    {
      bbutton[0] = 0;
    }
    if(bbutton[0] == 0)
    {
      zcontrol();
      intakecontrol();
    }
    else if(zpressed == 0 && intakepressed == 0)
    {
      btime = bpresstime % 400;
      if(btime < 200)
      {
      zmotor.spin(reverse, 40, pct);
      intake.spin(reverse, 60, pct);
      }
      else
      {
      zmotor.spin(fwd, 70, pct);
      intake.spin(fwd, 50, pct);
      }
    }
    else
    {
      zmotor.stop();
      intake.stop();
    }
  }
  else
  {
    zcontrol();
    intakecontrol();
  }
}
