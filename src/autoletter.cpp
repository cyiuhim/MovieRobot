//graphs for the writing of the letter on cody graph.png
//graph also on https://www.desmos.com/calculator/sy2qg4s3ms

#include "vex.h"
#include "auto.h"

void writec()
{ 
  penup();
  move(-200.5, 309.5, 1);
  pendown(0.3);
  wait(1, sec);
  drawarc(1, 45, 315, -250, 260, 5, 70);
  penup();
}
void writeo()
{
  move(-110, 330, 1);
  pendown(0.3);
  drawarc(1, 90, 500, -110, 260, 5, 70);
  penup();
}
void writed()
{
  move(-20, 330, 1);
  pendown(0.3);
  move(-20, 170, 2);
  wait(1, sec);
  penup();
  move(-20, 330, 2);
  wait(1, sec);
  pendown(0.3);
  move(0, 330, 0.4);
  drawarc(2, 90, -90, 0, 260, 5, 75);
  move(-50, 180, 1);
  penup();
}
void writey()
{   
  move(140, 290, 2);
  pendown(0.3);
  move(60, 370, 1.5);
  penup();
  move(140, 290, 1.5);
  pendown(0.3);
  move(200, 350, 1.5);
  penup();
  move(120, 290, 1.5);
  pendown(0.2);
  wait(0.5, sec);
  move(130, 190, 1.5);
  wait(1, sec);
  penup();
}

