int f(int n) {
    int i = 1;
    int x = 1;
    while (i <= n) {
        x = x * 1;
        i++;
    }
    i = 1;
    while (i <= n) {
        x = x + i;
        i++;
    }
    i = 1;
    while (i <= n) {
        x = x * 2;
        i++;
    }
    return x;
}