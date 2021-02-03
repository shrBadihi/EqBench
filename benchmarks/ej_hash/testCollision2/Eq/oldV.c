#include <stdio.h>
typedef struct oldV {
    int x;
    long y;
    int z;
}ejhash;
ejhash constructor(int x, long y, int z) {
		ejhash obj;
	    obj.x = x;
	    obj.y = y;
	    obj.z = z;
		return obj;
}
int hashCode(ejhash obj) {
    int h = obj.x;
	h = h * 31 + (int) (obj.y ^ (obj.y >> 32));
	h = h * 31 + obj.z;
	return h;
}
void testCollision2(long y1, int z1,long y2, int z2) {
	    ejhash o1 = constructor(1, y1, z1);
	    ejhash o2 = constructor(2, y2, z2);
	    if (hashCode(o1) == hashCode(o2)) {
	        printf("%s\n","Solved hash collision 2");
	    }
}