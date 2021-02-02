package benchmarks.CLEVER.UnchLoop.Neq;
public class newV{
	private int foo(int a, int b) {
		int c=0;
		for (int i=0;i<a;++i) {
			c=c+b;
		}
		return c+1;
	}
	int main() {
		return foo(6,900);
	}
}