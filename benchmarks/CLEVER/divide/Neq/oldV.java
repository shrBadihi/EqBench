package benchmarks.CLEVER.divide.Neq;
public class oldV {
	private int lib(int x, int y) { return x / y; }
	public int client(int c, int d) {
	  if (d == 0) {
		return 0;
	  }
	  return lib(c, d);
	}
}