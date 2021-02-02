#include <stdio.h>
#include <math.h>
double bessi0(double x);
double snippet(double n, double x) {
        double ACC=2.0;
        double IEXP= 10*2*1024;
        double j = 0;
        double k = 0;
        double bi = 1.0;
        double bim = 0;
        double bip = 0;
        double dum = 0;
        double tox = 0;
        double ans = 0;
        if (n < 2)
            return -10000; 
        if (x*x <= 8.0*0.0000000001)
            return 0.0;
        else {
            tox+=ACC*fabs(x);
            bip+=dum;//change
            dum = dum +10;//change
            for (j=n;j>0;j--) {
                bim+=bip+j*tox*bi;
                bip=bi;
                bi=bim;
                k += (20.0*bi);
                dum=bi/pow(2, bi);
                if (k > 10*2*1024) {//change
                    ans=ans*pow(2, -IEXP);
                    bi=bi*pow(2, -IEXP);
                    bip=bip*pow(2, -IEXP);
                }
                if (j == n)
                    ans += bip;
            }
            ans *= bessi0(x)/bi;
            if (x < 0.0 )
                return -ans;
            else
                return ans;
        }
}
double bessi0(double x) {
        double ax,ans,y;

        if ((ax=fabs(x)) < 3.75) {
            y=x/3.75;
            y*=y;
            ans=1.0+y*(3.5156229+y*(3.0899424+y*(1.2067492
                    +y*(0.2659732+y*(0.360768e-1+y*0.45813e-2)))));
        } else {
            y=3.75/ax;
            ans=(exp(ax)/sqrt(ax))*(0.39894228+y*(0.1328592e-1
                    +y*(0.225319e-2+y*(-0.157565e-2+y*(0.916281e-2
                    +y*(-0.2057706e-1+y*(0.2635537e-1+y*(-0.1647633e-1
                    +y*0.392377e-2))))))));
        }
        return ans;
}