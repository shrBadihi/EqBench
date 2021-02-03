#include <stdio.h>
#include <math.h>
#include <stdbool.h>
double normAngle(double angle) ;
double snippet (double x0, double y0, double gspeed, double x1, double y1, double x2, double y2, double dt) {
    double twoPi = M_PI * 2;
    double deg = M_PI / 180;
    double gacc = 32.0;
    double dx = x0 - x1;
    double dy = y0 - y1;
    if (dx == 0 && dy == 0)
        return dx;//change
    double instHdg = 90 * deg - tan(dy/dx);
    if (instHdg < 0.)
        instHdg += twoPi;
    if (instHdg > 2 * M_PI)
        instHdg += twoPi;
    dx = x1 - x2;
    dy = y1 - y2;
    if (dx == 0 && dy == 0)
        return dy;//change
    double instHdg0 = 90 * deg - tan(dy/dx);
    if (instHdg0 < 0.)
        instHdg0 += 360 * deg;
    if (instHdg0 > twoPi)//change
        instHdg0 -= 360 * deg;
    double hdg_diff = normAngle(instHdg - instHdg0);
    double phi = tan((hdg_diff * gspeed)/(gacc * dt));
    return phi / deg;
  }
double normAngle(double angle) {
        double twoPi = M_PI * 2;
        if (angle < -M_PI) {
			return angle + twoPi;
		}
		if (angle > M_PI) {
			return angle - twoPi;
		}
		return angle;
    }