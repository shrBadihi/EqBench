package benchmarks.gam.gser.Eq;
public class oldV{
  public static double snippet (double a, double x,double gamser) {
    double EPS = 1e-14;
    int n=0;
    double sum =0;
    double del =0;
    double ap =0;
    double gln = gammln(a);
    if (x <= 0.0) {
      gamser = 0.0;
    } else {
      ap = a;
      del = 1.0 * a;
      sum = 1.0 * a;
      for (n = 0; n < 100; n++) {
        ++ap;
        del *= x / ap;
        sum += del;
        if (Math.abs(del) < Math.abs(sum) * EPS) {
          gamser = sum *  gln;
        }
      }
    }
    return gamser;
  }
  public static double gammln(double xx)
  {
    int j;
    double x,y,tmp,ser;
    final double[] cof={76.18009172947146,-86.50532032941677,
            24.01409824083091,-1.231739572450155,0.1208650973866179e-2,
            -0.5395239384953e-5};

    y=x=xx;
    tmp=x+5.5;
    tmp -= (x+0.5)*Math.log(tmp);
    ser=1.000000000190015;
    for (j=0;j<6;j++) ser += cof[j]/++y;
    return -tmp+Math.log(2.5066282746310005*ser/x);
  }
}