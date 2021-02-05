package benchmarks.CLEVER.odd.Eq;
public class newV {
	private int lib(int x) {
		return (x+1) % 2;//change
	}
	int client(int x){
		if (lib(x)==0){
			   return 1;
		}else{
			return 0;
		}
	}
}