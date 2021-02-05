#include <stdio.h>
#include <math.h>
#include <stdbool.h>
typedef struct oldV {
	 double real;
	 double imag;
}complex;
double getreal(complex cs){
		return cs.real;
}
double getimag(complex cs){
		return cs.imag;
}
	complex constructor(double r,double i){
    complex cs;
		cs.real = r;
		cs.imag = i;
    return cs;
	}
	complex constructor2(){
    complex cs;
		cs.real = 0.0;
		cs.imag = 0.0;
    return cs;
	}
	complex assign(double r){
		complex cs;
		cs.real = r;
		cs.imag = 0;
    return cs;
	}
complex assignObj(complex c){
  		complex cs;
		cs.real = c.real;
		cs.imag = c.imag;
        return cs;
	}
	
  complex plus(complex a, complex c){
		return constructor(a.real+c.real,a.imag+c.imag);
	}
	
	 complex minus(complex a, complex c){
		return constructor(a.real-c.real,a.imag-c.imag);
	}
	
	 complex multiply(complex a, complex c){
		return constructor(a.real*c.real-a.imag*c.imag,a.real*c.imag+a.imag*c.real);
	}
	
complex divide(complex a,complex c){
		double d = sqrt(c.real * c.real) + sqrt(c.imag * c.imag);
		return constructor((a.real * c.real + a.imag * c.imag) / d, round((a.real * c.imag - a.imag * c.real) / d));
	}

complex cs;
void snippet(double x){
		const int MAXIT=100;
		const double EPS=1e-14;
		const double FPMIN=4.9E-324;
		const double BIG=1.7976931348623156E294;
		const double PI=3.141592653589793238, PIBY2=(PI/2.0), XMIN=1.5;
		bool odd;
		int k,n;
		double a,ax,fact,pix2,sign,sum,sumc,sums,term,test;
		complex b,cc,d,h,del;

		ax=fabs(x);
		if (ax < sqrt(FPMIN)) {
			cs = assign(ax);
		} else if (ax <= XMIN) {
			sum=sums=0.0;
			sumc=ax;
			sign=1.0;
			fact=PIBY2*ax*ax;
			odd=true;
			term=ax;
			n=3;
			for (k=1;k<=MAXIT;k++) {
				term *= fact/k;
				sum += sign*term/n;
				test=fabs(sum)*EPS;
				if (odd) {
					sign = -sign;
					sums=sum;
					sum=sumc;
				} else {
					sumc=sum;
					sum=sums;
				}
				if (term < test) break;
				odd=!odd;
				n += 2;
			}
			if (k > MAXIT)printf("%s\n","cf failed in frenel");
			cs=constructor(sumc,sums);
		} else {
			pix2=PI*ax*ax;
			b=constructor(1.0,-pix2);
			cc = assign(BIG);
			//		d=h=1.0/b;
			d=h=divide(constructor(1.0,0.0),b);
			n = -1;
			for (k=2;k<=MAXIT;k++) {
				n += 2;
				a = -n*(n+1);
				//b += 4.0;
				b = assignObj(plus(b,constructor(4.0,0.0)));
				//d=1.0/(a*d+b);
				d = assignObj(divide(constructor(1.0,0.0),plus(multiply(d,constructor(a,0)),b)));
				cc=plus(b, divide(constructor(a,0.0),cc));
				del=multiply(cc,d);
				h = multiply(h,del);
				if (fabs(getreal(del)-1.0)+fabs(getimag(del)) <= EPS) break;
			}
			if (k > MAXIT) printf("maxits exceeded in cisi");
			h = multiply(h,constructor(ax,-ax));
			cs=multiply(constructor(0.5,0.5),(minus(constructor(1.0,0.0),multiply(constructor(cos(0.5*pix2),sin(0.5*pix2)),h))));
		}
		if (x < 0.0) {change
			cs = constructor(-getreal(cs),-getimag(cs));;
		}
		return;
  }
  void cisi(double x){
		const int MAXIT=100;
		const double EULER=0.577215664901533, PIBY2=1.570796326794897, TMIN=2.0;
		const double EPS=1e-14;
		const double FPMIN=2.0E-323;
		const double BIG=1.7976931348623156E294;
		int i,k;
		bool odd;
		double a,err,fact,sign,sum,sumc,sums,t,term;
		complex h,b,c,d,del;

		t=fabs(x);
		if (t == 0.0) {
			cs= constructor(-BIG,0.0);
			return;
		}
		if (t > TMIN) {
			b=constructor(1.0,t);
			c=constructor(BIG,0.0);
      complex temp=constructor(1.0,0.0);
			d=h=divide(temp,b);
			for (i=1;i<MAXIT;i++) {
				a= -i*i;
        temp=constructor(2.0,0.0);
				b = plus(temp,b);
        temp=constructor(1.0,0.0);
        complex temp2=constructor(a,0.0);
        complex temp3=multiply(temp2,d);
				d=divide(temp, plus(temp3,b));
				c = plus(b,divide(temp2,c));//c=b+a/c;
				del=multiply(c,d);				//del=c*d;
				h=multiply(h,del);//h *= del;
				if (fabs(getreal(del)-1.0)+fabs(getreal(del)) <= EPS) 
        break;
			}
			if (i >= MAXIT) 
        printf("%s\n","cf failed in cisi");
        temp = constructor(cos(t),-sin(t));
			h=multiply(temp,h);
      temp=constructor(-getreal(h),getimag(h));
			cs= plus(temp,constructor(0.0,PIBY2));
		} else {
			if (t < sqrt(FPMIN)) {
				sumc=0.0;
				sums=t;
			} else {
				sum=sums=sumc=0.0;
				sign=fact=1.0;
				odd=true;
				for (k=1;k<=MAXIT;k++) {
					fact *= t/k;
					term=fact/k;
					sum += sign*term;
					err=term/fabs(sum);
					if (odd) {
						sign = -sign;
						sums=sum;
						sum=sumc;
					} else {
						sumc=sum;
						sum=sums;
					}
					if (err < EPS) break;
					odd=!odd;
				}
				if (k > MAXIT) printf("maxits exceeded in cisi");
			}
			cs=constructor(sumc+log(t)+EULER,sums);
		}
		if (x < 0.0) cs = constructor(getreal(cs),-getimag(cs));
	}
