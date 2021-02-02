package benchmarks.ej_hash.testCollision4.Eq;
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
	    h = h * 31 + (int) (y ^ (y >>> 32));
	    h = h * 31 + z;
	    return h;
    }
    public static void testCollision4(int x1, long y1, int z1) {
		newV o1 = new newV(1234, Double.doubleToRawLongBits(3.14159E123), 3141);
		newV o2 = new newV(x1, y1, z1);
		x1=z1;//change
		if (o1.hashCode() == o2.hashCode()) {
			System.out.println("Solved hash collision 4");
		}
	}
}