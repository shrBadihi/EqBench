package benchmarks.REVE.whileif.Eq;
public class oldV {
	int f(int t, int c) {
		int x = 0;
		if(0 < t) {
		  while(0 < c) {
			x ++;
			c = c-1;
		  }
		}
		return x;
	}
}