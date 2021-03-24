package benchmarks.bess.SIGN.Eq;
public class newV{
    public static double snippet(double a, double b) {
        if (a >= 0 && b >= 0)//change
            return a;
        if (a < 0 && b < 0)//change
            return a;
        else 
            return -a;//change    
    }
}