package benchmarks.CLEVER.LoopSub.Neq;
public class oldV {
	private int foo(int a, int b) {
		int c=a;
		for (int i=0;i<3;++i)
			c-=b;
		return c;
	}
	public int main() {
		return foo(5,900);
	}
}