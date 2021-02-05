package benchmarks.CLEVER.pos.Eq;
public class newV {
	private int lib(int x) {
		if (x < 0){
			return -x;
		}else{
			return x;
		}
	}
	int client(int x){
		if (x > 0) {
			return -lib(-x);
		}else{
			return lib(x);
		}
	}
}