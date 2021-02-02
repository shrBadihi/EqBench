package benchmarks.optimization.wood.NEq;
public class oldV{
    public final static void wood(double x1, double x2, double x3, double x4) {
        if ((10.0 * (x2 - x1 * x1)) == 0.0 && (5.0 - x1) == 0.0
            && (Math.sqrt(64) * (x4 - x3 * x3)) == 0.0
            && (2.0 - x3) == 0.0) {
          System.out.println("Solved Wood constraint");
        }
    }
}