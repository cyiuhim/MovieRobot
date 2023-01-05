#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor29 leftdrive = motor29(Brain.ThreeWirePort.D, false);
motor29 rightdrive = motor29(Brain.ThreeWirePort.B, true);
controller Controller1 = controller(primary);
motor yright = motor(PORT9, ratio36_1, true);
motor xmotor = motor(PORT5, ratio18_1, true);
motor29 intake = motor29(Brain.ThreeWirePort.A, false);
motor29 zmotor = motor29(Brain.ThreeWirePort.H, false);
motor ymotor = motor(PORT8, ratio36_1, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}