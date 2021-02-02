package benchmarks.CLEVER.Comp.Eq;
public class oldV {
	private int foo(int a, int b){
		if (a>b)
		  return 1;
		return 0;
	}
	public int main() {
		int x=2;
		int y=3;
		int z=foo(x,y);
		if (z==0) {
			int tmp=y;
		  	y=x;
		  	x=tmp;
	  	}
		return y;
	}
}