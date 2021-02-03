#include <stdio.h>
#include <math.h>
#include <stdbool.h>
double snippet(double xx) {
        int j=0;
        double x = 0.0;
        double y= 0.0;
        double tmp= 0.0;
        double ser= 0;
        double cof[6]={76.18009172947146,-86.50532032941677, 24.01409824083091,-1.231739572450155,0.1208650973866179e-2, -0.5395239384953e-5};
        x = xx;
        y = x;
        tmp=x+5.5;
        //tmp -= (x+0.5)*log(tmp);
        ser=1.000000000190015;
        for (j=0;j<6;j++)
            ser += cof[j]*++y;
        return -tmp+log(2.5066282746310005*ser/x);
}