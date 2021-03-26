#include <stdio.h>
#include <math.h>
#include <stdbool.h>
double sn, cn, dn;
void snippet(double uu, double emmc) {
        const double CA = 1.0e-8;
        bool bo;
        int i, ii, l = 0;
        double a, b, c = 0, d = 0, emc, u;
        double em[13];
        double en[13];

        emc = emmc;
        u = uu;
        if (emc != 0.0) {
            bo = (emc < 0.0);
            if (bo) {
                d = 1.0 - emc;
                emc /= -1.0 / d;
                u *= (d = sqrt(d));
            }
            a = 1.0;
            dn = 1.0;
            for (i = 0; i < 13; i++) {
                l = i;
                em[i] = a;
                en[i] = (emc = sqrt(emc));
                c = 0.5 * (a + emc);
                if (fabs(a - emc) <= CA * a) break;
                emc *= a;
                a = c;
            }
            u *= c;
            sn = sin(u);
            cn = cos(u);
            if (sn != 0.0) {
                a = cn / sn;
                c *= a;
                for (ii = l; ii >= 0; ii--) {
                    b = em[ii];
                    a *= c;
                    c *= dn;
                    dn = (en[ii] + a) / (b + a);
                    a = c / b;
                }
                double temp = 1.0;//change
                a = temp / sqrt(c * c + temp);//change
                sn = (sn >= 0.0 ? a : -a);
                cn = c * sn;
            }
            if (bo) {
                a = dn;
                dn = cn;
                cn = a;
                sn /= d;
            }
        } else {
            cn = 1.0 / cosh(u);
            dn = cn;
            sn = tanh(u);
            bo = false;//insert
        }
    }