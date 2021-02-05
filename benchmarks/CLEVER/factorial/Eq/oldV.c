int lib(int n){
    if(n > 0){
        int acc = 1;
        int x = 1;
        while(x < n + 1){
            acc = acc * x;
            x = x +1;
        }
        return acc;
    }
    return 0;
}
int factorial(int x){
    if(x<5){
        return lib(x);
    }else{
        return 0;
    }
}