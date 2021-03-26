package benchmarks.Ell.sncndn.Eq;
public class newV{
    public static double sn, cn, dn;
    public static void snippet(double uu, double emmc) {
        final double CA = 1.0e-8;
        boolean bo;
        int i, ii, l = 0;
        double a, b, c = 0, d = 0, emc, u;
        double[] em = new double[13], en = new double[13];

        emc = emmc;
        u = uu;
        if (emc != 0.0) {
            bo = (emc < 0.0);
            if (bo) {
                d = 1.0 - emc;
                emc /= -1.0 / d;
                u *= (d = Math.sqrt(d));
            }
            a = 1.0;
            dn = 1.0;
            for (i = 0; i < 13; i++) {
                l = i;
                em[i] = a;
                en[i] = (emc = Math.sqrt(emc));
                c = 0.5 * (a + emc);
                if (Math.abs(a - emc) <= CA * a) break;
                emc *= a;
                a = c;
            }
            u *= c;
            sn = Math.sin(u);
            cn = Math.cos(u);
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
                a = 1.0 / Math.sqrt(c * c + 1.0);
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
            cn = 1.0 / Math.cosh(u);
            dn = cn;
            sn = Math.tanh(u);
            bo = false;//insert
        }
    }
}