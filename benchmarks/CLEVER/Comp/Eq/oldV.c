int foo(int a, int b) {
	if (a>b)
	  return 1;
	return 0;
}
int main(void) {
	int x=2;
	int y=3;
	int z=foo(x,y);
	if (!z) {
		int tmp=y;
		  y=x;
		  x=tmp;
	  }
	return y;
}