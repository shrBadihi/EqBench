package benchmarks.REVE.loop2.Eq;
public class oldV {
	int f(int n) {
		int i = 1;
		int j = 0;
		while (i <= n) {
			j = j + 2;
			i++;
		}
		return j;
	}
}