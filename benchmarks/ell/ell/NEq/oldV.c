#include <stdio.h>
#include <math.h>
#include <stdbool.h>
double SQR(double a);
double SIGN(double a, double b);
double MAX(double a, double b);
double MIN(double a, double b);
double rf(double x, double y, double z);
double rd(double x, double y, double z);
double snippet (double phi, double ak) {
    double cc =0;
    double q =0;
    double s=0;
    s=sin(phi);
    cc=SQR(cos(phi));
    q=(1.0-s*ak)*(1.0+s*ak);
    double ans = sin(phi)*(rf(cc,q,1.0)-(SQR(s*ak))*rd(cc,q,1.0)/3.0);
    return ans ;
  }
double SQR(double a) {
    return a*a;
  }
double SIGN(double a, double b){
    return b >= 0 ? (a >= 0 ? a : -a) : (a >= 0 ? -a : a);
  }
double MAX(double a, double b){
    return b > a ? (b) : (a);
  }
double MIN(double a, double b){
    return b < a ? (b) : (a);
  }
double rf(double x, double y, double z){
    const double ERRTOL=0.0025, TINY=1.5e-38, BIG=3.0e37, THIRD=1.0/3.0;
    const double C1=1.0/24.0, C2=0.1, C3=3.0/44.0, C4=1.0/14.0;
    double alamb,ave,delx,dely,delz,e2,e3,sqrtx,sqrty,sqrtz,xt,yt,zt;

    if (MIN(MIN(x,y),z) < 0.0 || MIN(MIN(x+y,x+z),y+z) < TINY ||
            MAX(MAX(x,y),z) > BIG)
    printf("%s\n","invalid arguments in rf");
    xt=x;
    yt=y;
    zt=z;
    do {
      sqrtx=sqrt(xt);
      sqrty=sqrt(yt);
      sqrtz=sqrt(zt);
      alamb=sqrtx*(sqrty+sqrtz)+sqrty*sqrtz;
      xt=0.25*(xt+alamb);
      yt=0.25*(yt+alamb);
      zt=0.25*(zt+alamb);
      ave=THIRD*(xt+yt+zt);
      delx=(ave-xt)/ave;
      dely=(ave-yt)/ave;
      delz=(ave-zt)/ave;
    } while (MAX(MAX(fabs(delx),fabs(dely)),fabs(delz)) > ERRTOL);
    e2=delx*dely-delz*delz;
    e3=delx*dely*delz;
    return (1.0+(C1*e2-C2-C3*e3)*e2+C4*e3)/sqrt(ave);
  }

double rd(double x, double y, double z){
    const double ERRTOL=0.0015, TINY=1.0e-25, BIG=4.5e21;
    const double C1=3.0/14.0, C2=1.0/6.0, C3=9.0/22.0;
    const double C4=3.0/26.0, C5=0.25*C3, C6=1.5*C4;
    double alamb,ave,delx,dely,delz,ea,eb,ec,ed,ee,fac,sqrtx,sqrty,
            sqrtz,sum,xt,yt,zt;

    if (MIN(x,y) < 0.0 || MIN(x+y,z) < TINY || MAX(MAX(x,y),z) > BIG)
      printf("%s\n","invalid arguments in rd");
    xt=x;
    yt=y;
    zt=z;
    sum=0.0;
    fac=1.0;
    do {
      sqrtx=sqrt(xt);
      sqrty=sqrt(yt);
      sqrtz=sqrt(zt);
      alamb=sqrtx*(sqrty+sqrtz)+sqrty*sqrtz;
      sum += fac/(sqrtz*(zt+alamb));
      fac=0.25*fac;
      xt=0.25*(xt+alamb);
      yt=0.25*(yt+alamb);
      zt=0.25*(zt+alamb);
      ave=0.2*(xt+yt+3.0*zt);
      delx=(ave-xt)/ave;
      dely=(ave-yt)/ave;
      delz=(ave-zt)/ave;
    } while (MAX(MAX(fabs(delx),fabs(dely)),fabs(delz)) > ERRTOL);
    ea=delx*dely;
    eb=delz*delz;
    ec=ea-eb;
    ed=ea-6.0*eb;
    ee=ed+ec+ec;
    return 3.0*sum+fac*(1.0+ed*(-C1+C5*ed-C6*delz*ee)
            +delz*(C2*ee+delz*(-C3*ec+delz*C4*ea)))/(ave*sqrt(ave));
  }