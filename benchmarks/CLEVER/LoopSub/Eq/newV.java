package benchmarks.CLEVER.LoopSub.Eq;
public class newV {
	private int foo(int a, int b) {
		int c=b;
		for (int i=0;i<3;++i)
			c-=a;
		return c;
	}
	public int main() {
		return foo(900,5);
	}
}