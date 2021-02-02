int f(int n) {
    int i = 1;
    int j = 0;
    if (n < 1) {
        n = 1;
    }
    while (i <= n) {
        j = j + 2;
        i++;
    }
    return j;
}