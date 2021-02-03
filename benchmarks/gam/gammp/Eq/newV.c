#include <stdio.h>
#include <math.h>
#include <stdbool.h>
double sn, cn, dn;
double gammln(double xx);
double gser(double a, double x, double gln,double gamser);
double gcf(double a, double x, double gln);
double snippet (double a, double x, double gamser, double gammcf, double gln) {
    if (x < 0.0 || a <= 0.0)
      return -1000;
    if (x < a+1.0) {
      return gser(a,x, gln,gamser);//change
    } else {
      return 1.0-gcf(a,x,gln);//change
    }
}
double gser(double a, double x, double gln,double gamser){
    int ITMAX=100;
    double EPS=1e-14;
    int n;
    double sum,del,ap;

    gln=gammln(a);
    if (x <= 0.0) {
      if (x < 0.0) printf("%s\n","x less than 0 in routine gser");
      gamser=0.0;
      return gamser;
    } else {
      ap=a;
      del=sum=1.0/a;
      for (n=0;n<ITMAX;n++) {
        ++ap;
        del *= x/ap;
        sum += del;
        if (fabs(del) < fabs(sum)*EPS) {
          gamser=sum*exp(-x+a*log(x)-gln);
          return gamser;
        }
      }
      printf("%s\n","a too large, ITMAX too small in routine gser");
      return gamser;
    }
  }
double gcf(double a, double x, double gln){
    const int ITMAX=100;
    const double EPS=1e-14;
    const double FPMIN=4.9E-324/EPS;
    int i;
    double an,b,c,d,del,h;

    b=x+1.0-a;
    c=1.0/FPMIN;
    d=1.0/b;
    h=d;
    for (i=1;i<=ITMAX;i++) {
      an = -i*(i-a);
      b += 2.0;
      d=an*d+b;
      if (fabs(d) < FPMIN) d=FPMIN;
      c=b+an/c;
      if (fabs(c) < FPMIN) c=FPMIN;
      d=1.0/d;
      del=d*c;
      h *= del;
      if (fabs(del-1.0) <= EPS) break;
    }
    if (i > ITMAX) printf("%s\n","a too large, ITMAX too small in gcf");
    return exp(-x+a*log(x)-gln)*h;
  }
double gammln(double xx)
  {
    int j;
    double x,y,tmp,ser;
    const double cof[6]={76.18009172947146,-86.50532032941677,
            24.01409824083091,-1.231739572450155,0.1208650973866179e-2,
            -0.5395239384953e-5};

    y=x=xx;
    tmp=x+5.5;
    tmp -= (x+0.5)*log(tmp);
    ser=1.000000000190015;
    for (j=0;j<6;j++) ser += cof[j]/++y;
    return -tmp+log(2.5066282746310005*ser/x);
 }
