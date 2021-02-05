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
void testCollision3(long y1, long y2) {
	    ejhash o1 = constructor(1234, y1, 3141);
	    ejhash o2 = constructor(5678, y2, 3141);
	    if (hashCode(o1) == hashCode(o2)) {
	        printf("%s\n","Solved hash collision 3");
	    }
}