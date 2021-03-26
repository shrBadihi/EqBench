#include <stdio.h>
#include <math.h>
double chebev_c1d(double a, double b,int m, double x);
double ai;
double bi;
double aip;
double bip;
double ri,rk,rip,rkp;
double rj,ry,rjp,ryp;
double gam1,gam2,gampl,gammi;
double c1_d[7] = {
			-1.142022680371168e0,6.5165112670737e-3,
			3.087090173086e-4,-3.4706269649e-6,6.9437664e-9,
			3.67795e-11,-1.356e-13};
double c2_d[8] = {
			1.843740587300905e0,-7.68528408447867e-2,
			1.2719271366546e-3,-4.9717367042e-6,-3.31261198e-8,
			2.423096e-10,-1.702e-13,-1.49e-15};
void beschb(double x) {
	const int NUSE1=7, NUSE2=8;
	double xx;
	xx=8.0*x*x-1.0;
	gam1=chebev_c1d(-1.0,1.0,NUSE1,xx);
	gam2=chebev_c1d(-1.0,1.0,NUSE2,xx);
	gampl= gam2-x*gam1;
	gammi= gam2+x*gam1;
}
double chebev_c1d(double a, double b,int m, double x) {
    double d=0.0;
    double dd=0.0;
    double sv,y,y2;
		int j;
		if ((x-a)*(x-b) > 0.0)
			printf("%s\n","x not in range in routine chebev");
		y2=2.0*(y=(2.0*x-a-b)/(b-a));
		for (j=m-1;j>0;j--) {
			sv=d;
			d=y2*d-dd+c1_d[j];
			dd=sv;
    } 
		return y*d-dd+0.5*c1_d[0];
}
double MAX(double a, double b){
    if (b > a)
      return b;
    else
      return a;
}	
double SIGN(double a, double b){
    if (b >= 0){
      if (a >= 0)
          return a;
      else
          return -a;
    }
    else {
      if (a >= 0)
          return -a;
      else
          return a;
    }
}	
void sphbes(int n,double x){
    
    const double RTPIO2=1.253314137315500251;
    double factor,order;
    double sj,sy,sjp,syp;
    if((n<0||x<=0.0)){
        printf("%s\n","bad arguments in sphbes");
    }
    order = n+0.5;
    factor = RTPIO2/sqrt(x);
    sj = factor*rj;
    sy = factor*ry;
    sjp = factor*rjp-sj/(2.0*x);
    syp = factor*ryp-sy/(2.0*x);
}