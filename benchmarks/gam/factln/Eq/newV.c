#include <stdio.h>
#include <math.h>
#include <stdbool.h>
double sn, cn, dn;
double gammln(double xx);
double factln( int n){
		double a[101]; 
		if (n <= 1){
		    if (n < 0) printf("%s\n","Negative factorial in routine factln");//change
			return 0.0;
		}
		if (n <= 100)
			return (a[n] != 0.0 ? a[n] : (a[n]=gammln(n+1.0)));
		else return gammln(n+1.0);
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