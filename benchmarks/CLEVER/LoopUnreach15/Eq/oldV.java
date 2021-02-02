package benchmarks.CLEVER.LoopUnreach15.Eq;
public class oldV {
	private int foo(int a, int b) {
		int c=0;
		if (a<0) {
			for (int i=1;i<=b;++i)
				c+=a;
		}
		return c;
	}
	public int main(int x) {
		if (x>=13 && x<16)
			return foo(x,15);
		return 0;
	}
}