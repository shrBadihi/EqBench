package benchmarks.ej_hash.testCollision3.Eq;
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
	    int h = x;
	    h = h * 31 + (int) (y ^ (y >> 32));
	    h = h * 31 + z;
	    return h;
    }
    public static void testCollision3(long y1, long y2) {
		int z = 3141;//change
		newV o1 = new newV(1234, y1, z);//change
		newV o2 = new newV(5678, y2, z);//change
		if (o1.hashCode() == o2.hashCode()) {
			System.out.println("Solved hash collision 3");
		}
	}
}