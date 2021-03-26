package benchmarks.ej_hash.ej_hash.Neq;
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
	    //h = h * 31 + z;//change
	    return h;
    }
    public static void testCollision1(int x1, long y1, int z1,int x2, long y2, int z2) {
	    newV o1 = new newV(x1, y1, z1);
	    newV o2 = new newV(z2, y2, x2);//change
	    if (o1.hashCode() == o2.hashCode()) {
	        System.out.println("Solved hash collision 1");
	    }
    }
	public static void testCollision2(long y1, int z1,long y2, int z2) {
		newV o1 = new newV(1, y1, z1);
		newV o2 = new newV(2, y2, z2);
		if (o1.hashCode() == o2.hashCode()) {
	    	System.out.println("Solved hash collision 2");
		}
		else//change
			System.out.println("Not equal");//change
    }
	public static void testCollision3(long y1, long y2) {
		newV o1 = new newV(5678, y1, 3141);//change
		newV o2 = new newV(5678, y2, 3141);
		if (o1.hashCode() == o2.hashCode()) {
			System.out.println("collision Occures");//change
		}
	}
	public static void testCollision4(int x1, long y1, int z1) {
		newV o1 = new newV(1234, Double.doubleToRawLongBits(3.14159E123), 3141);
		newV o2 = new newV(x1, y1, z1);
		if (o1.hashCode() == o2.hashCode() && y1==z1) {//change
			System.out.println("Solved hash collision 4");
		}
	}
}