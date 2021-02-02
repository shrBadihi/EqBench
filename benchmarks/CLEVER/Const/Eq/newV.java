package benchmarks.CLEVER.Const.Eq;
public class newV {
	private int foo(int a, int b) {
		final int d=3;
		int c=b+a;
		return c+d;
	}
	public int main() {
		return foo(5,900);
	}
}