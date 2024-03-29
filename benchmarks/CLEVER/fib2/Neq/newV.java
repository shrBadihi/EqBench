package benchmarks.CLEVER.fib2.Neq;
public class newV {
	private int lib(int n){
		int a = 0;
		int b = 1;
		int i = 0;
		while(i < n){
			i += 1;
			a = b;
			b = a + b;
		}
		return a;
	}
	public int fib(int x){
		if(x<5){
			return lib(x);
		}else{
			return 0;
		}
	}
}