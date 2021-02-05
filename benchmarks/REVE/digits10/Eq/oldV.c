int f(int n) {
  int result = 1;
  n = n/10;
  while (n > 0) {
    result++;
    n = n / 10;
    if (n > 0) {
      result++;
      n = n / 10;
      if (n > 0) {
        result++;
        n = n / 10;
        if (n > 0) {
          result++;
          n = n / 10;
        }
      }
    }
  }
  return result;
}