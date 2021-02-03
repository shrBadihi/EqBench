#include <stdio.h>
#include <math.h>
#include <stdbool.h>
double SQR(double a);
double snippet (double a, double b) {
        double absa = 0;
        double absb = 0;
        absa=fabs(a);
        absb=fabs(b);
        if (absa > absb){
            return absa*sqrt(1.0+SQR(absb/absa));
        }
        else {
            if (absb != 0.0 )//change
                return absb * sqrt(1.0 + SQR(absa / absb));//change
            else
                return absb;//change
        }
}
double SQR(double a) {
        return a*a;
}