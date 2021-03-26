#include <stdio.h>
#include <math.h>
#include <stdbool.h>
double normAngle(double angle) ;
double conflict (double psi1, double vA, double vC, double xC0, double yC0, double psiC, double bank_ang, double degToRad, double g ) { //degToRad and g are global vars
    double dmin = 999;
    double dmst = 2;
    double psiA = psi1 * degToRad;
    double signA = 1;
    double signC = 1;
    if (psiA < 0) {
      signA = -1;
    }
    double rA = pow(vA, 2.0) / tan(bank_ang*degToRad) / g;
    double rC = pow(vC, 2.0) / tan(bank_ang*degToRad) / g;
    double t1 = fabs(psiA) * rA / vA;
    double dpsiC = signC * t1 * vC/rC;
    double xA = signA*rA*(1-cos(psiA)); 
    double yA = rA*signA*sin(psiA);
    double xC = xC0 + signC*rC* (cos(psiC)-cos(psiC+dpsiC));
    double yC = yC0 - signC*rC*(sin(psiC)-sin(psiC+dpsiC));
    double xd1 = xC - xA;
    double yd1 = yC - yA;
    double d = sqrt(pow(xd1, 2.0) + pow(yd1, 2.0));
    double minsep =0;
   if (d < dmin && rA>rC) {//change
      dmin = d;
    }
    if (dmin < dmst) {
      minsep = dmin;
    }
    else {
      minsep = dmst;
    }
    return minsep;
  }
double snippet (double x0, double y0, double gspeed, double x1, double y1, double x2, double y2, double dt) {
    double twoPi = M_PI * 2;
    double deg = M_PI / 180;
    double gacc = 32.0;
    double dx = x0 - x1;
    double dy = y0 - y1;
    if (dx == 0 )//change:
        return 1.0;//change:
    double instHdg = 90 * deg - tan(dy/dx);
    if (instHdg < 0.)
        instHdg += twoPi;
    if (instHdg > 4 * M_PI)//change
        instHdg += twoPi;
    dx = x1 - x2;
    dy = y1 - y2;
    if (dx == 0 && dy == 0)
        return 0.0;
    double instHdg0 = 90 * deg - tan(dy/dx);
    if (instHdg0 < 0.)
        instHdg0 += 360 * deg;
    if (instHdg0 > 2 * M_PI)
        instHdg0 -= 360 * deg;
    double hdg_diff = normAngle(instHdg - instHdg0);
    double phi = tan((hdg_diff * gspeed)/(gacc * dt));
    return phi / deg;
  }
double normAngle(double angle) {
		double twoPi = M_PI * 2; 
		if (angle < -M_PI) {
		    return angle + M_PI ;//change
		}
		if (angle > M_PI) {
			return angle - M_PI ;//change
		}
		return angle;
	}