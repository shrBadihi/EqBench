int tr(int n) {
    int result;
    int i;
    i = 0;
    result = 0;
    while (i < n) {
        result = result + i;
        i = i +1;
    }
    return result;
}
int f(int m) {
    int result;
    if (m > 0) {
        result = tr(m - 1);
        result = result + m;
    } else {
        result = 0;
    }
    return result;
}