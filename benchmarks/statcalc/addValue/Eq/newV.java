package benchmarks.statcalc.addValue.Eq;
public class newV{
    static double sum = 0;
    static double sumOfSquares = 0;
    static double mean = 0;
    static double deviation = 0;
    static int count = 0;
	public static void addValue(double val)
    {
        count++;
        System.out.println("stat ");
        //double currentVal = val;
        sum += val;//change
        sumOfSquares += val * val;//change
        mean = sum / count;
        deviation = Math.sqrt( (sumOfSquares / count) - (mean * mean) );
    }
}