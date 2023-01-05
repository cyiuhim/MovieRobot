/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\cyiuh                                            */
/*    Created:      Fri May 14 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// leftdrive            motor29       D               
// rightdrive           motor29       B               
// Controller1          controller                    
// yright               motor         9               
// xmotor               motor         5               
// ymotor               motor         8               
// zmotor               motor29       H               
// intake               motor29       A               
// ---- END VEXCODE CONFIGURED DEVICES ----
#include "math.h"
#include "vex.h"
#include "vex_timer.h"
#include "vex_controller.h"
#include "cody.h"
#include "init.h"
#include "auto.h"
#include "opcontrol.h"
using namespace vex;
competition competition1;


void auton()
{
  writec();
  writeo();
  writed(); 
  writey(); 
}

void maincontrol()
{
  init();
  xoriginal = 0;
  automode = 0;
  while(true)
  {
 
    if(Controller1.ButtonA.pressing())
    {
    automode = 1;
    }
    else
    {
      automode = 0;
    }
    if(automode == 1)
    {
    auton();
    wait(3, sec);
    }
    else
    {
    bcontrol();
    }
    wait(10, msec);
  }

  }
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  competition1.drivercontrol(maincontrol);
}
