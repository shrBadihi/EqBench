package benchmarks.ej_hash.testCollision1.NEq;
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
    public static void testCollision1(int x1, long y1, int z1,int x2, long y2, int z2) {
	    oldV o1 = new oldV(x1, y1, z1);
	    oldV o2 = new oldV(x2, y2, z2);
	    if (o1.hashCode() == o2.hashCode()) {
	        System.out.println("Solved hash collision 1");
	    }
    }
}