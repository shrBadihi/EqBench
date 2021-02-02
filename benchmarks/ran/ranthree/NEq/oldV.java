package benchmarks.Ran.ranthree.NEq;
public class oldV{
	public static double snippet(int idum){//&idum
		int inext = 0,inextp = 0;
		int iff=0;
		final int MBIG=1000000000,MSEED=161803398,MZ=0;
		final double FAC=(1.0/MBIG);
		int[] ma = new int[56];
		int i,ii,k,mj,mk;
		if (idum < 0 || iff == 0) {
			iff=1;
			mj=Math.abs(MSEED-Math.abs(idum));
			mj %= MBIG;
			ma[55]=mj;
			mk=1;
			for (i=1;i<=54;i++) {
				ii=(21*i) % 55;
				ma[ii]=mk;
				mk=mj-mk;
				if (mk < (int)(MZ)) mk += MBIG;
				mj=ma[ii];
			}
			for (k=0;k<4;k++)
				for (i=1;i<=55;i++) {
					ma[i] -= ma[1+(i+30) % 55];
					if (ma[i] < (int)(MZ)) 
						ma[i] += MBIG;
				}
			inext=0;
			inextp=31;
			idum=1;
		}
		if (++inext == 56) 
			inext=1;
		if (++inextp == 56) 
			inextp=1;
		mj=ma[inext]-ma[inextp];
		if (mj < (int)(MZ)) 
			mj += MBIG;
		ma[inext]=mj;
		return mj*FAC;
	}
}