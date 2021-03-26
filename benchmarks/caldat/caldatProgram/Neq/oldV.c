#include <stdio.h>
#include <math.h>
int julday( int mmj,  int idj,  int iyyyj);
int snippet (int IYBEG) {
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
                if (idwk != 5) {//change
                    n=(int) (12.37*(iyyy-1900+(im-0.5)/12.0));
                    icon=0;
                    for (int u = 0;u<2;u++) {
                        frac=24.0*(frac+timzon);
                        if (frac < 0.0) {
                            --jd;
                            frac += 24.0;
                        }
                        if (frac == frac) {//cahnge
                            ++jd;
                            frac -= 12.0;
                        }
                        else
                            frac += 12.0;
                        if (jd != jday) {//change
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
int julday( int mmj,  int idj,  int iyyyj)
{
        double IGREG=15.0+31.0*(10.0+12.0*1582.0);
        double ja =1.0;
        double jul=0.0;
        double jy=iyyyj;
        double jm=0.0;
        if (jy == 0.0) 
           return 0.0;
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
        return jul;
}