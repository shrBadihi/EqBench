package benchmarks.tsafe.normAngle.Eq;
public class newV{
	public static double snippet (double angle) {
		double temp = Math.PI * 2; //change
		if (angle < -Math.PI) {
			return angle + temp;//change
		}
		if (angle > Math.PI) {
			return angle - temp;//change
		}
		return angle;
	}
}