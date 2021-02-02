package benchmarks.ej_hash.hashCode.Eq;
public class newV{
    private final int x;
    private final long y;
    private final int z;
    public newV(int x, long y, int z) {
	    this.x = x;
	    this.y = y;
	    this.z = z;
    }
    @Override
    public int hashCode() {
	    //int h = x;//change
	    int h = x * 31 + (int) (y ^ (y >>> 32));//change
	    h = h * 31 + z;
	    return h;
    }
}