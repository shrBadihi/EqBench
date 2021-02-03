#include <stdio.h>
typedef struct newV {
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
    //int h = x;//change
    int h = obj.x * 31 + (int) (obj.y ^ (obj.y >> 32));//change
	h = h * 31 + obj.z;
	return h;
}