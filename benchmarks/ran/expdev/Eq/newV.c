#include <stdio.h>
#include <math.h>
#include <stdbool.h>
double ran1(double idum);
double snippet(int idumx, int idum) {
        idum = idumx;
        double dumRenamed = 0.0;
        do{
            dumRenamed = ran1(idumx);//change
        }while (dumRenamed == 0.0);
        return -log(dumRenamed);
}
double ran1(double idum){
        int IA=16807;
        int IM=2147483647;
        int IQ=127773;
        int IR=2836;
        int NTAB=32;
        int NDIV=(1+(IM-1)/NTAB);
        double EPS=3.0e-16;
        double AM=1.0/IM;
        double RNMX=(1.0-EPS);
        int iy=0;
        int iv[NTAB] ;
        int j,k;
        double temp;
        if (idum <= 0 || iy == 0) {
            if (-idum < 1)
                idum=1;
            else
                idum = -idum;
            for (j=NTAB+7;j>=0;j--) {
                k= (int) (idum/IQ);
                idum=IA*(idum-k*IQ)-IR*k;
                if (idum < 0)
                    idum += IM;
                if (j < NTAB)
                    iv[j] = (int) idum;
            }
            iy=iv[0];
        }
        k= (int) (idum/IQ);
        idum=IA*(idum-k*IQ)-IR*k;
        if (idum < 0)
            idum += IM;
        j=iy/NDIV;
        iy=iv[j];
        iv[j] = (int) idum;
        if ((temp=AM*iy) > RNMX)
            return RNMX;
        else
            return temp;
    }