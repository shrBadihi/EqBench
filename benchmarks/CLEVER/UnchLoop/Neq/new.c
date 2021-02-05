int foo(int a, int b) {
	int c=0;
	for (int i=0;i<a;++i) {
		c=c+b;
	}
	return c+1;
}
int main(void) {
	return foo(6,900);
}