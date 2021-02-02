package benchmarks.CLEVER.getSign2.Eq;
public class newV {
	private int lib(int x) {
		if (x <= 0)
		   return -1;
		else
		   return 1;
	  }
	public int client(int x){
		if (x > 0) {
		  return lib(x);
		}
		return x;
	  }
}