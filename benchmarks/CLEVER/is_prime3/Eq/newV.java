package benchmarks.CLEVER.is_prime3.Eq;
public class newV {
	int NUMPRIMES = 8;
	int[] primes = { 2, 3, 5, 7, 11, 13, 17, 19 };
	private boolean lib(int x, int b) {
		if (b == 0) {
		  return false;
		} else {
		  for (int i = 0; i < NUMPRIMES; i++) {
			int mod = x % primes[i];
			if (mod == 0)
				return x == primes[i];
		  }
		}
		return true;
	  }
	public boolean client(int x) { 
		for (int i = 0; i < NUMPRIMES; i++) {
			if (x == primes[i])
			  return 1;
		  }
		  return lib(x,1);
	}
}