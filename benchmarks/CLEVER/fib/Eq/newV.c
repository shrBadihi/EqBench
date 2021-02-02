int lib(int n){
    int a = 0;
    int b = 1;
    int i = 0;
    while(i < n){
        i += 1;
        a = b;
        b = a + b;
    }
    return a;
}
int fib(int x){
    if(x<5){
        return lib(x);
    }else{
        return 0;
    }
 }