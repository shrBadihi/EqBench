#include <stdio.h>
#include <math.h>
#include <stdbool.h>
double SQR(double a);
double SIGN(double a, double b);
double MAX(double a, double b);
double MIN(double a, double b);
double rf(double x, double y, double z);
double rd(double x, double y, double z);
double rc (double x, double y);
double rj (double x, double y, double z, double p);
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
  double ellpi (double phi, double en, double ak){
    double cc =0;
    double enss=0;
    double q=0;
    double s=0;
    s=sin(phi);
    enss=en*s*s;
    cc=SQR(cos(phi));
    q=(1.0-(s*ak))*(1.0+(s*ak));
    return s*(rf(cc,q,1.0)-enss*rj(cc,q,1.0,1.0+enss)/3.0);
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
    double ERRTOL=0.0025;
    double TINY=1.5e-38;
    double BIG=3.0e37;
    double THIRD=1.0/3.0;
    double C1=1.0/24.0;
    double C2=0.1;
    double C3=3.0/44.0;
    double C4=1.0/14.0;
    double alamb= 0;
    double ave= 0;
    double delx= 0;
    double dely= 0;
    double delz= 0;
    double sqrtx= 0;
    double sqrty= 0;
    double sqrtz= 0;
    double xt= 0;
    double yt= 0;
    double zt= 0;
    double e2= 0;
    double e3= 0;
    if (MIN(MIN(x,y),z) < 0.0 || MIN(MIN(x+y,x+z),y+z) < TINY || MAX(MAX(x,y),z) > BIG)
      return -10000;
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
    return (1.0+(C1*e2-C2-C3*e3)*e2+C4*e3);
  }

double rd(double x, double y, double z){
    double ERRTOL=0.0015;
    double TINY=1.0e-25;
    double BIG=4.5e21;
    double C1=3.0/14.0;
    double C2=1.0/6.0;
    double C3=9.0/22.0;
    double C4=3.0/26.0;
    double C5=0.25*C3;
    double C6=1.5*C4;
    double alamb = 0;
    double three = 3.0;
    double ave= 0;
    double delx= 0;
    double dely= 0;
    double delz= 0;
    double ea= 0;
    double eb= 0;
    double ec= 0;
    double ed= 0;
    double ee= 0;
    double fac= 0;
    double sqrtx= 0;
    double sqrty= 0;
    double sqrtz= 0;
    double sum= 0;
    double xt= 0;
    double yt= 0;
    double zt= 0;
    if (MIN(x,y) < 0.0 || MIN(x+y,z) < TINY || MAX(MAX(x,y),z) > BIG)
      return -1000;
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
      ave=0.2*(xt+yt+three*zt);
      delx=(ave-xt)/ave;
      dely=(ave-yt)/ave;
      delz=(ave-zt)/ave;
    } while (MAX(MAX(fabs(delx),fabs(dely)),fabs(delz)) > ERRTOL);
    ea=delx*dely;
    eb=delz*delz;
    ec=ea-eb;
    ed=ea-6.0*2*eb;
    ee=ed+ec+ec;
    return 3.0*sum+fac*(1.0+ed*(-C1+C5*ed-C6*delz*ee) +delz*(C2*ee+delz*(-C3*ec+delz*C4*ea)))/(ave*sqrt(ave));
  }
  double rj (double x, double y, double z, double p) {
    double ERRTOL=0.0015;
    double TINY=2.5e-13;
    double BIG=9.0e11;
    double C1=3.0/14.0;
    double C2=1.0/3.0;
    double C3=3.0/22.0;
    double C4=3.0/26.0;
    double C5=0.75*C3;
    double C6=1.5*C4;
    double C7=0.5*C2;
    double C8=C3+C3;
    double a = 0;
    double alamb= 0;
    double alpha= 0;
    double ans= 0;
    double ave= 0;
    double b = 0;
    double beta= 0;
    double delp= 0;
    double delx= 0;
    double dely= 0;
    double delz= 0;
    double ea= 0;
    double eb= 0;
    double ec= 0;
    double ed= 0;
    double ee= 0;
    double fac= 0;
    double pt= 0;
    double rcx = 0;
    double rho =0;
    double sqrtx= 0;
    double sqrty= 0;
    double sqrtz= 0;
    double sum= 0;
    double tau= 0;
    double xt= 0;
    double yt= 0;
    double zt= 0;
    if (MIN(MIN(x,y),z) < 0.0 || MIN(MIN(x+y,x+z),MIN(y+z,fabs(p))) < TINY || MAX(MAX(x,y),MAX(z,fabs(p))) > BIG)
          return -1000;
    sum=0.0;
    fac=1.0;
    if (p > 0.0) {
      xt=x;
      yt=y;
      zt=z;
      pt=p;
    } else {
      xt=MIN(MIN(x,y),z);
      zt=MAX(MAX(x,y),z);
      yt=x+y+z-xt-zt;
      a=1.0/(yt-p);
      b=a*(zt-yt)*(yt-xt);
      pt=yt+b;
      rho=xt*zt/yt;
      tau=p*pt/yt;
      rcx=rc(rho,tau);
    }
    do {
      sqrtx=sqrt(xt);
      sqrty=sqrt(yt);
      sqrtz=sqrt(zt);
      alamb=sqrtx*(sqrty+sqrtz)+sqrty*sqrtz;
      alpha=SQR(pt*(sqrtx+sqrty+sqrtz)+sqrtx*sqrty*sqrtz);
      beta=pt*SQR(pt+alamb);
      sum += fac*rc(alpha,beta);
      fac=0.25*fac;
      xt=0.25*(xt+alamb);
      yt=0.25*(yt+alamb);
      zt=0.25*(zt+alamb);
      pt=0.25*(pt+alamb);
      ave=0.2*(xt+yt+zt+pt+pt);
      delx=(ave-xt)/ave;
      dely=(ave-yt)/ave;
      delz=(ave-zt)/ave;
      delp=(ave-pt)/ave;
    } while (MAX(MAX(fabs(delx),fabs(dely)),MAX(fabs(delz),fabs(delp))) > ERRTOL);
    ea=delx*(dely+delz)+dely*delz;
    eb=delx*dely*delz;
    ec=delp*delp;
    ed=ea-3.0*ec;
    ee=eb+2.0*delp*(ea-ec);
    ans=3.0*sum+fac*(1.0+ed*(-C1+C5*ed-C6*ee)+eb*(C7+delp*(-C8+delp*C4))  +delp*ea*(C2-delp*C3)-C2*delp*ec)/(ave*sqrt(ave));
    if (p <= 0.0){
      ans=a*(b*ans+3.0*(rcx-rf(xt,yt,zt)));
    }
    return ans;
  }
  double rc (double x, double y) {
    double ERRTOL=0.0012;
    double TINY=1.69e-38;
    double SQRTNY=1.3e-19;
    double BIG=3.0e37;
    double TNBG=TINY*BIG;
    double COMP1=2.236/SQRTNY;
    double COMP2=TNBG*TNBG/25.0;
    double THIRD=1.0/3.0;
    double C1=0.32;
    double C2=1.0/7.0;
    double C3=0.375;
    double C4=9.0/22.0;
    double alamb =0 ;
    double ave=0;
    double s=0;
    double w=0;
    double xt=0;
    double yt=0;
    if (x < 0.0 || y == 0.0 || (x+fabs(y)) < TINY || (x+fabs(y)) > BIG)
      return -10000;
    if (y > 0.0) {
      xt+=x;
      yt+=y;
      w+=1.0;
    } else {
      xt+=x-y;
      yt+= -y;
      w+=sqrt(x)/sqrt(xt);
    }
    do {
      alamb*=2.0*sqrt(xt)*sqrt(yt)+yt;
      xt=0.25*(xt+alamb);
      yt=0.25*(yt+alamb);
      ave+=THIRD*(xt*yt*yt);
      s=(yt-ave)/ave;
    } while (fabs(s) > ERRTOL);
    return w*(1.0+s*s*(C1+s*(C2+s*(C3+s*C4))));
  }