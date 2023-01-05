#include "vex.h"
#include "init.h"
#include "cody.h"
#include "opcontrol.h"


void init()
{
  bbutton[0] = 0;
  bbutton[1] = 0;
  ymotor.resetPosition();
  yright.resetPosition();
  xmotor.resetPosition();
  ymotor.setStopping(hold);
  yright.setStopping(hold);
  xmotor.setStopping(hold);
  Brain.Screen.clearScreen();
  Brain.Screen.drawImageFromBuffer(cody, 0, 0, 334080); // 334080 = 480 * 232 * 3(to bytes)
  ymotor.startRotateTo(190, deg, 40, rpm); //reset position
  yright.rotateTo(190, deg, 40, rpm);
  yoriginal = 190;
}