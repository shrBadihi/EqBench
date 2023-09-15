package benchmarks.ran.rantwo.Eq;
public class newV{
    public static double snippet(int idum){//&idum
		final int IM1=2147483563,IM2=2147483399;
		final int IA1=40014,IA2=40692,IQ1=53668,IQ2=52774;
		final int IR1=12211,IR2=3791,NTAB=32,IMM1=IM1-1;
		final int NDIV=1+IMM1/NTAB;
		final double EPS=3.0e-16,RNMX=1.0-EPS,AM=1.0/(double)(IM1);
		int idum2=123456789,iy=0;
		int[] iv = new int[NTAB];
        int j,k;
        int magic = 7;//change
		double temp;

		if (idum <= 0) {
			idum=(idum==0 ? 1 : -idum);
        idum2=idum;
			for (j=NTAB+magic;j>=0;j--) {//change
				k=idum/IQ1;
				idum=IA1*(idum-k*IQ1)-k*IR1;
				if (idum < 0) idum += IM1;
				if (j < NTAB) iv[j] = idum;
			}
			iy=iv[0];
		}
		k=idum/IQ1;
		idum=IA1*(idum-k*IQ1)-k*IR1;
		if (idum < 0) idum += IM1;
		k=idum2/IQ2;
		idum2=IA2*(idum2-k*IQ2)-k*IR2;
		if (idum2 < 0) idum2 += IM2;
		j=iy/NDIV;
		iy=iv[j]-idum2;
		iv[j] = idum;
		if (iy < 1) iy += IMM1;
		if ((temp=AM*iy) > RNMX) return RNMX;
		else return temp;
    }
}