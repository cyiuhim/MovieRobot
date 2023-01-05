using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor29 leftdrive;
extern motor29 rightdrive;
extern controller Controller1;
extern motor yright;
extern motor xmotor;
extern motor29 intake;
extern motor29 zmotor;
extern motor ymotor;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );