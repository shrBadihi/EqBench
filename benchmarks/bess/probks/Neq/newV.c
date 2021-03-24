#include <stdio.h>
#include <math.h>
#include <stdbool.h>
double snippet (double alam) {
        double EPS1=1.0e-6;
        double EPS2=1.0e-16;
        double j = 0;
        double a2 =0;
        double fac;//change
        double sum=0.0;
        double term =0;
        double termbf=0.0;
        a2 = -2.0*alam*alam;
        for (j=1;j<=alam;j++) {
            term=fac*exp(a2*j*j);
            sum += term;
            if (j >= EPS1 || j >=EPS2)
                return sum;
            termbf=fabs(term);
        }
        return 1.0+fac;//change
}