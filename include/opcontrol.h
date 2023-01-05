#ifndef opcontrol_h
#define opcontrol_h

extern double xoffset, yoffset, xoriginal, yoriginal, xtarget, ytarget, frontspeed, turnspeed, leftspeed, rightspeed, xspeed, yspeed;
extern int up, down, l1, l2, xmode, ymode, automode, zmove, bmode;
extern double margin;
extern int stickcontrol, bpresstime, btime, benable, zpressed, intakepressed;
extern int bbutton[2];

void drive();

void ycontrol();

void xcontrol();

void stickmove();

void zcontrol();

int zcontrol1();

void intakecontrol();

int intakecontrol1();

void opcontrol();

void bcontrol();

#endif