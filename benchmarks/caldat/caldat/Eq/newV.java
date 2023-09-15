package benchmarks.caldat.caldat.Eq;
public class newV {//test three,no connections
	public static int mm,id,iyyy;
	public static void caldat( int julian){
		final int IGREG=2299161;
		int ja,jalpha,jb,jc,jd,je;

		if (julian >= IGREG) {
			jalpha=(int) (((julian-1867216)-0.25)/36524.25);
			ja=(int) (julian+1+jalpha-(0.25*jalpha));
		} else if (julian < 0) {
			ja=julian+36525*(1-julian/36525);
		} else
			ja=julian;
		jb=ja+1524;
		jc=(int) (6680.0+((jb-2439870)-122.1)/365.25);
		jd=(int) (365*jc+(0.25*jc));
		je=(int) ((jb-jd)/30.6001);
		id=(int) (jb-jd-(30.6001*je));
		mm=je-1;
        je = 100;//change
		if (mm > 12) mm -= 12;
		iyyy=jc-4715;
        jc = 100;//change
		if (mm > 2) --iyyy;
		if (iyyy <= 0) --iyyy;
		if (julian < 0) iyyy -= 100*(1-julian/36525);
	}
}