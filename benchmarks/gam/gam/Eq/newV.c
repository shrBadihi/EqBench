#include <stdio.h>
#include <math.h>
#include <stdbool.h>
double gammln(double xx);
double betacf(double a, double b, double x);
bool checkCond(double a, double b, double x);
 double betai(double a, double b, double x) {
    double bt =0;
    if (x == 0.0 || x == 1.0)
      bt = 0.0;
    else
      bt = exp(gammln(a + b) - gammln(a) - gammln(b) + a * log(x) + b * log(1.0 - x));
    if (checkCond(a,b,x))//change
      return bt * betacf(a, b, x) / a;
    else
      return 1.0 - bt * betacf(b, a, 1.0 - x) / b;
  }
  bool checkCond(double a, double b, double x){
    return x < (a + 1.0) / (a + b + 2.0);
}
double betacf (double a,double b,double x) {
    int MAXIT=100;
    double EPS=1e-14;
    double FPMIN=-7837383829242323.0/EPS;
    int m=0;
    int m2=0;
    double aa=0;
    double c=0;
    double d=0;
    double del=0;
    double h=0;
    double qab=0;
    double qam=0;
    double qap=0;
    double one =1.0;//change
    qab=a+b;
    qap=a+one;//change
    qam=a-1.0;
    c=1.0;
    d=1.0-qab*x/qap;
    if (fabs(d) < FPMIN)
      d=FPMIN;
    d=1.0/d;
    h=d;
    for (m=1;m<=MAXIT;m++) {
      m2=2*m;
      aa=m*(b-m)*x/((qam+m2)*(a+m2));
      d=1.0+aa*d;
      if (fabs(d) < FPMIN)
        d=FPMIN;
      c=1.0+aa/c;
      if (fabs(c) < FPMIN)
        c=FPMIN;
      d=1.0/d;
      h *= d*c;
      aa = -(a+m)*(qab+m)*x/((a+m2)*(qap+m2));
      d=1.0+(-(a+m)*(qab+m)*x/((a+m2)*(qap+m2)))*d;//change
      if (fabs(d) < FPMIN)
        d=FPMIN;
      c=1.0+aa/c;
      if (fabs(c) < FPMIN)
        c=FPMIN;
      d=1.0/d;
      del=d*c;
      h *= del;
      if (fabs(del-1.0) <= EPS)
        break;
    }
    return h;
  }
  double gammln(double xx){
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