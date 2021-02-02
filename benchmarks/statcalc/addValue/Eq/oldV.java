package benchmarks.Statcalc.addValue.Eq;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
public class oldV implements Serializable{
    static List<Double> values = new ArrayList<Double>();
    static double sum = 0;
    static double sumOfSquares = 0;
    static double mean = 0;
    static double deviation = 0;
    static int count = 0;
	public static void addValue(double val)
    {
        if((int)val > 10) {
    		System.out.println("10");
    	}
        int index = Collections.binarySearch(values, val);
        if (index >= 0 && index < values.size())
        {
            values.add(index, val);
        }
        else if (index == values.size() || values.size() == 0)
        {
            values.add(val);
        }
        else
        {
            values.add((index * (-1)) - 1, val);
        }
        count++;
        System.out.println("stat ");
        double currentVal = val;
        sum += currentVal;
        sumOfSquares += currentVal * currentVal;
        mean = sum / count;
        deviation = Math.sqrt( (sumOfSquares / count) - (mean * mean) );
    }
}