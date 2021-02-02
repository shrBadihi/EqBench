package benchmarks.REVE.nestedwhile.Eq;
public class newV {
	int f(int x, int g) {
		int i = 0;
		while (i < x) {
			i = i + 1;
			g = g - 1;
			while (x < i) {
				x = x + 1;
				g = g + 1;
			}
		}
		return g;
	}
}