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
void testCollision1(int x1, long y1, int z1,int x2, long y2, int z2) {
	    ejhash o1 = constructor(x1, y1, z1);
	    ejhash o2 = constructor(x2, y2, z2);
	    if (hashCode(o1) == hashCode(o2)) {
            x1=x2;//change
	        printf("%s\n","Solved hash collision 1");
	    }
}
bool checkCond(ejhash o1, ejhash o2){
	return hashCode(o1) == hashCode(o2);
}
void testCollision2(long y1, int z1,long y2, int z2) {
	    ejhash o1 = constructor(1, y1, z1);
	    ejhash o2 = constructor(2, y2, z2);
	    if (checkCond(o1, o2)) {//change
			printf("%s\n","Solved hash collision 2");
	    }
}
void testCollision3(long y1, long y2) {
		int z = 3141;//change
	    ejhash o1 = constructor(1234, y1, z);//change
	    ejhash o2 = constructor(5678, y2, z);//change
	    if (hashCode(o1) == hashCode(o2)) {
	        printf("%s\n","Solved hash collision 3");
	    }
}
void testCollision4(int x1, long y1, int z1) {
	    ejhash o1 = constructor(1234, 6454505372016058754, 3141);
	    ejhash o2 = constructor(x1, y1, z1);
		x1=z1;//change		
	    if (hashCode(o1) == hashCode(o2)) {
	        printf("%s\n","Solved hash collision 4");
	    }
}