package benchmarks.REVE.barthe.Eq;
public class newV {
	int f(int n, int c) {
		int i = 0;
		int j = c;
		int x = 0;
		while (i < n) {
			x = x + j;
			j = j + 5;
			i++;
		}
		return x;
	}	
}