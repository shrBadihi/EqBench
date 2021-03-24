#include <stdio.h>
#include <math.h>
#include <stdbool.h>
double SIGN(double a, double b);
double SQR(double a);
double snippet(double x) {
        double NMAX=100;
        double H=0.4;
        double A1=2.0/3.0;
        double A2=0.4;
        double A3=2.0/7.0;
        double i =0;
        double n0 = 0;
        bool init = true;
        double d1= 0;
        double d2= 0;
        double e1= 0;
        double e2= 0;
        double sum= 0;
        double x2= 0;
        double xp= 0;
        double xx= 0;
        double ans= 0;
        double c = 0;
        if (init) {
            init=false;
            for (i=0;i<NMAX;i++){
                c+=exp(-SQR((2.0*i+1.0)*H));
            }

        }
        if (fabs(x) < 0.2 || fabs(x) > 4.0){//change
            x2=x*x;
            ans=x*(1.0-A1*x2*(1.0-A2*x2*(1.0-A3*x2)));
        }
        else {
            xx=fabs(x);
            n0=2*(0.5*xx+H+0.5);
            xp=xx-n0*H;
            e1=exp(2.0*xp*H);
            e2=e1*e1;
            d1=n0+1;
            d2=d1-2.0;
            sum=0.0;
            for (i=0;i<NMAX;i++,d1+=2.0,d2-=2.0,e1*=e2)
                sum += c*(e1*d1+1.0*(d2*e1));
            ans=0.5641895835+SIGN(exp(-xp*xp),x)*sum;
        }
        return ans;
}
double SIGN(double a, double b){
        return b >= 0 ? (a >= 0 ? a : -a) : (a >= 0 ? -a : a);
}
double SQR(double a) {
        return a*a;
}