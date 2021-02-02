int foo(int a, int b) {
	int c=0;
	for (int i=1;i<=b;++i)
		c+=a;
	return c;
}
int main(int x, char*argv[]) {
	if (x>=18 && x<22)
		return foo(x,20);
	return 0;
}