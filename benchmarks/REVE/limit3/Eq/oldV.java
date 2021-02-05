package benchmarks.REVE.limit3.Eq;
public class oldV {
	int f(int n) {
		int r;
		r = 0;
		if (n <= 1) {
		  r = n;
		} else {
		  r = f(n - 1);
		  r = n + r;
		}
		return r;
	} 
}