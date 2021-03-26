package benchmarks.ej_hash.ej_hash.Eq;
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
	    int h = x * 31 + (int) (y ^ (y >> 32));//change
	    h = h * 31 + z;
	    return h;
    }
    public static void testCollision1(int x1, long y1, int z1,int x2, long y2, int z2) {
	    newV o1 = new newV(x1, y1, z1);
	    newV o2 = new newV(x2, y2, z2);
	    if (o1.hashCode() == o2.hashCode()) {
            x1=x2;//change
	        System.out.println("Solved hash collision 1");
	    }
    }
	public static void testCollision2(long y1, int z1,long y2, int z2) {
		newV o1 = new newV(1, y1, z1);
		newV o2 = new newV(2, y2, z2);
		if (checkCond(o1,o2)) {//change
			System.out.println("Solved hash collision 2");
		}
    }
	public static  boolean checkCond(newV o1, newV o2){
		return o1.hashCode() == o2.hashCode();
	}
	public static void testCollision3(long y1, long y2) {
		int z = 3141;//change
		newV o1 = new newV(1234, y1, z);//change
		newV o2 = new newV(5678, y2, z);//change
		if (o1.hashCode() == o2.hashCode()) {
			System.out.println("Solved hash collision 3");
		}
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