#include <stdio.h>
#include <math.h>
#include <stdbool.h>
double sn, cn, dn;
double gammln(double xx);
double factrl(int n){
		int ntop=4;
		double a[5] ={1.0,1.0,2.0,6.0,24.0};
		int j;
		if (n < 0) printf("%s\n","Negative factorial in routine factrl");
		if (n > 32) return exp(gammln(n+1.0));
		while (ntop<n) {
			j=ntop++;
			a[ntop]=a[j]*ntop;
		}
		return a[n];
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