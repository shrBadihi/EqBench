package benchmarks.CLEVER.factorial.Neq;
public class newV {
	private int lib(int n){
		if(n <= 0){
			return 1;
		}else{
			return n * lib(n-1);
		}
	}
	public int factorial(int x){
		if(x<5){
			return lib(x);
		}else{
			return 0;
		}
	}
}