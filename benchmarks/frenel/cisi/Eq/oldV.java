package benchmarks.frenel.cisi.Eq;
public class oldV {
	private static complex cs;
	public static void snippet(double x){
		final int MAXIT=100;
		final double EULER=0.577215664901533, PIBY2=1.570796326794897, TMIN=2.0;
		final double EPS=1e-14;
		final double FPMIN=Double.MIN_VALUE*4.0;
		final double BIG=Double.MAX_VALUE*EPS;
		int i,k;
		boolean odd;
		double a,err,fact,sign,sum,sumc,sums,t,term;
		complex h,b,c,d,del;

		t=Math.abs(x);
		if (t == 0.0) {
			cs= new complex(-BIG,0.0);
			return;
		}
		if (t > TMIN) {
			b=new complex(1.0,t);
			c=new complex(BIG,0.0);
			d=h=new complex(1.0,0.0).divide(b);
			for (i=1;i<MAXIT;i++) {
				a= -i*i;
				b = new complex(2.0,0.0).plus(b);
				d=new complex(1.0,0.0).divide(new complex(a,0.0).multiply(d).plus(b));
				c = b.plus(new complex(a,0.0).divide(c));//c=b+a/c;
				del=c.multiply(d);				//del=c*d;
				h=h.multiply(del);//h *= del;
				if (Math.abs(del.getreal()-1.0)+Math.abs(del.getreal()) <= EPS) break;
			}
			if (i >= MAXIT) System.out.println("cf failed in cisi");
			h=new complex(Math.cos(t),-Math.sin(t)).multiply(h);
			cs= new complex(-h.getreal(),h.getimag()).plus(new complex(0.0,PIBY2));
		} else {
			if (t < Math.sqrt(FPMIN)) {
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
					err=term/Math.abs(sum);
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
				if (k > MAXIT) System.out.println("maxits exceeded in cisi");
			}
			cs=new complex(sumc+Math.log(t)+EULER,sums);
		}
		if (x < 0.0) cs = new complex(cs.getreal(),-cs.getimag());
	}
	public static void frenel(double x){
		final int MAXIT=100;
		final double EPS=1e-14;
		final double FPMIN=Double.MIN_VALUE;
		final double BIG=Double.MAX_VALUE*EPS;
		final double PI=3.141592653589793238, PIBY2=(PI/2.0), XMIN=1.5;
		boolean odd;
		int k,n;
		double a,ax,fact,pix2,sign,sum,sumc,sums,term,test;
		complex b,cc = null,d,h,del;

		ax=Math.abs(x);
		if (ax < Math.sqrt(FPMIN)) {
			cs.assign(ax);
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
				test=Math.abs(sum)*EPS;
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
			if (k > MAXIT) System.out.println("series failed in frenel");
			cs=new complex(sumc,sums);
		} else {
			pix2=PI*ax*ax;
			b=new complex(1.0,-pix2);
			cc.assign(BIG);
			//		d=h=1.0/b;
			d=h=new complex(1.0,0.0).divide(b);
			n = -1;
			for (k=2;k<=MAXIT;k++) {
				n += 2;
				a = -n*(n+1);
				//b += 4.0;
				b.assign(b.plus(new complex(4.0,0.0)));
				//d=1.0/(a*d+b);
				d.assign(new complex(1.0,0.0).divide(d.multiply(new complex(a,0)).plus(b)));
				cc=b.plus(new complex(a,0.0).divide(cc));
				del=cc.multiply(d);
				h = h.multiply(del);
				if (Math.abs(del.getreal()-1.0)+Math.abs(del.getimag()) <= EPS) break;
			}
			if (k > MAXIT) System.out.println("cf failed in frenel");
			h = h.multiply(new complex(ax,-ax));
			cs=new complex(0.5,0.5).multiply((new complex(1.0,0.0).minus(new complex(Math.cos(0.5*pix2),Math.sin(0.5*pix2)).multiply(h))));
		}
		if (x < 0.0) {
			cs = new complex(-cs.getreal(),-cs.getimag());;
		}
		return;
  }
}
class complex{
	private double real;
	private double imag;
	
	public double getreal(){
		return real;
	}
	
	public double getimag(){
		return imag;
	}
	
	public complex(double r,double i){
		r = real;
		i = imag;
	}
	
	public complex(){
		real = 0.0;
		imag = 0.0;
	}
	
	public void assign(double r){
		real = r;
		imag = 0;
	}
	public void assign(complex c){
		real = c.real;
		imag = c.imag;
	}
	
	public complex plus(complex c){
		return new complex(real+c.real,imag+c.imag);
	}
	
	public complex minus(complex c){
		return new complex(real-c.real,imag-c.imag);
	}
	
	public complex multiply(complex c){
		return new complex(real*c.real-imag*c.imag,real*c.imag+imag*c.real);
	}
	
	public complex divide(complex c){
		double d = Math.sqrt(c.real * c.real) + Math.sqrt(c.imag * c.imag);
		return new complex((real * c.real + imag * c.imag) / d, Math.round((real * c.imag - imag * c.real) / d));
	}
}