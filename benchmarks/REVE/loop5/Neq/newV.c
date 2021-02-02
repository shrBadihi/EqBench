int f(int n) {
  int i;
  int j;
  i = n + 1;
  j = 0;
  while (i > 0) {
    j = j + 2;
    i = i - 1;
  }
  return j;
}