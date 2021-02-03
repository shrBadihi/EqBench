#include <stdio.h>
#include <math.h>
#include <stdbool.h>
double snippet (double psi1, double vA, double vC, double xC0, double yC0, double psiC, double bank_ang, double degToRad, double g ) { //degToRad and g are global vars
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
    if (d < dmin) {
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