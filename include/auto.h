#ifndef auto_h
#define auto_h

extern double originaly, originalx, xvelocity, yvelocity, xgoal, ygoal;
extern double speedconst, pi;
extern int moveno;

void penup();

void pendown(double time);

void move(double xcoor, double ycoor, double movetime);

void drawarc(int direction, int startdeg, int enddeg, double xcentre, double ycentre, int increment, double radius);

void move(double xcoor, double ycoor, double movetime);

void writec();

void writeo();

void writed();

void writey();

#endif