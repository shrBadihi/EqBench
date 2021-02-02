package benchmarks.CLEVER.LoopMult5.Eq;
public class oldV {
	private int foo(int a, int b) {
		int c=0;
		for (int i=1;i<=b;++i)
			c+=a;
		return c;
	}
	public int main(int x) {
		if (x>=5 && x<7)
			return foo(x,5);
		return 0;
	}
}