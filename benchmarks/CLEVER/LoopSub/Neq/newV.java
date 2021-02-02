package benchmarks.CLEVER.LoopSub.Neq;
public class newV {
	private int foo(int a, int b) {
		int c=b;
		for (int i=0;i<2;++i)
			c-=a;
		return c;
	}
	public int main() {
		return foo(900,5);
	}
}