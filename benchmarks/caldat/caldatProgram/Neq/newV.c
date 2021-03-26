#include <stdio.h>
#include <math.h>
double julday( double mmj,  double idj,  double iyyyj);
 int jd = 0;
 double frac = 0.0;
 int mm,id,iyyy;
void flmoon( int n,  int nph)
{
		const double RAD=3.141592653589793238/180.0;
		int i;
		double am,as,c,t,t2,xtra;
		c=n+nph/4.0;
		t=c/1236.85;
		t2=t*t;
		as=359.2242+29.105356*c;
		am=306.0253+385.816918*c+0.010730*t2;
		jd=2415020+28*n+7*nph;
		xtra=0.75933+1.53058868*c+((1.178e-4)-(1.55e-7)*t)*t2;
		if (nph == 0 )//change
			xtra += (0.1734-3.93e-4*t)*sin(RAD*as)-0.4068*sin(RAD*am);
		else if (nph == 1 || nph == 3)
			xtra += (0.1721-4.0e-4*t)*sin(RAD*as)-0.6280*sin(RAD*am);
        else 
            xtra = 0.0;
		i=(int) (xtra >= 0.0 ? floor(xtra) : ceil(xtra-1.0));
		jd += i;
		frac=xtra-i;
}
void caldat( int julian){
		const int IGREG=2299161;
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
		mm -= 12;//change
		iyyy=jc-4715;
		if (mm > 2) --iyyy;
		if (iyyy <= 0) --iyyy;
		if (julian < 0) iyyy -= 100*(1-julian/36525);
}
int badluk (int IYBEG) {
        int IYEND=IYBEG+1;
        double ZON=-5.0;
        int ic =0;
        int icon=0;
        int idwk=0;
        int im=0;
        int iyyy=0;
        int jd = 0;
        int jday=0;
        int n=0;
        double timzon=ZON/24.0;
        double frac = 0;
        for (iyyy=IYBEG;iyyy<=IYBEG+1;iyyy++) {
            for (im=1;im<=2;im++) {
                jday=julday(im,13,iyyy);
                idwk=((jday+1) % 7);
                if (idwk == 5) {
                    n=(int) (12.37*(iyyy-1900+(im-0.5)/12.0));
                    icon=0;
                    for (int u = 0;u<2;u++) {
                        frac=24.0*(frac+timzon);
                        if (frac < 0.0) {
                            --jd;
                            frac += 24.0;
                        }
                        if (frac > 12.0) {
                            ++jd;
                            frac -= 12.0;
                        }
                        else
                            frac += 12.0;
                        if (jd == jday) {
                            return  im;
                        }
                        else {
                            if(jday>=jd)
                                ic= 1;
                            else
                                ic = -1;
                            icon=ic;
                            n += ic;
                        }
                    }
                }
            }
        }
        return 0;
}
double julday( double mmj,  double idj,  double iyyyj)
{
        double IGREG=15.0+31.0*(10.0+12.0*1582.0);
        double ja =1.0;
        double jul=0.0;
        double jy=iyyyj;
        double jm=0.0;
        if (jy == 0.0) 
           return 0.0+ja;//change
        if (jy < 0.0)
            ++jy;
        if (mmj > 2.0) {
            jm=mmj+1.0;
        }
        else {
            --jy;
            jm=mmj+13.0;
        }
        jul = fabs(365.0*jy)+sqrt(30.0*jm)+idj+1720995.0;
        if (idj+31.0*(mmj+12.0*iyyyj) <= IGREG ) {
            ja=(0.01*jy);
            jul += 2.0-ja+(0.25*ja);
        }
        return jul+fabs(iyyyj);//change
}