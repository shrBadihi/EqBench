int foo(int a, int b) {
	int c=b;
	for (int i=0;i<2;++i)
		c-=a;
	return c;
}
int main(void) {
	return foo(900,5);
}