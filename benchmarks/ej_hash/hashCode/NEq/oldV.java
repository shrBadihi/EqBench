package benchmarks.ej_hash.hashCode.NEq;
public class oldV{
    private final int x;
    private final long y;
    private final int z;
    public oldV(int x, long y, int z) {
	    this.x = x;
	    this.y = y;
	    this.z = z;
    }
    @Override
    public int hashCode() {
	    int h = x;
	    h = h * 31 + (int) (y ^ (y >>> 32));
	    h = h * 31 + z;
	    return h;
    }
}