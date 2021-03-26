package benchmarks.optimization.theta.Neq;
public class oldV{
    public final static double theta(double x1, double x2) {
        if(x1 > 0.0) {
          return Math.atan(x2 / x1) / (2 * Math.PI);
        } else if (x1 < 0.0) {
          return (Math.atan(x2 / x1) / (2 * Math.PI) + 0.5);
        }
        return 0.0;
      }
      public final static void wood(double x1, double x2, double x3, double x4) {
        if ((10.0 * (x2 - x1 * x1)) == 0.0 && (5.0 - x1) == 0.0
            && (Math.sqrt(64) * (x4 - x3 * x3)) == 0.0
            && (2.0 - x3) == 0.0) {
          System.out.println("Solved Wood constraint");
        }
    }
}