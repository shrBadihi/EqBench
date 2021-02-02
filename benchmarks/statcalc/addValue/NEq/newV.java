package benchmarks.Statcalc.addValue.NEq;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
public class newV implements Serializable{
    static List<Double> values = new ArrayList<Double>();
    static double sum = 0;
    static double sumOfSquares = 0;
    static double mean = 0;
    static double deviation = 0;
    static int count = 0;
	public static void addValue(double val)
    {
        if((int)val > 10 || (int)val < -10) {//change
    		System.out.println("Out of bound");//change
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