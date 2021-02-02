int lib(int x) {
	int counter = 1;//change
	while (x < 0) {
		x++;
		counter++;
	}
	return counter;
}
int client(int x){
	if (x > 0) {
		return -lib(-x);
	}else{
		return lib(x);
	}
}