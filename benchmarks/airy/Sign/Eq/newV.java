package benchmarks.airy.Sign.Eq;
public class newV{
    public static double snippet(double a, double b) {
        if ((a >= 0 && b >= 0) || (a < 0 && b < 0))//change
            return a;
        else 
            return -a;//change    
    }
}