package benchmarks.CLEVER.oneN2.Neq;
public class newV {
	private int lib(int x){
		if (x > 10)
        return 11;
      else
        return x+1;
    }
	int client(int x){
		if (x > lib(x))
			return x;
		else
			return lib(x);
	}
}