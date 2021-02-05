#define NUMPRIMES 8
static const unsigned int primes[8] = { 2, 3, 5, 7, 11, 13, 17, 19 };
int lib(unsigned int x, int b) {
  if (b == 0) {
    return 0;
  } else {
    for (int i = 0; i < NUMPRIMES; i++) {
      int mod = x % primes[i];
      if (mod == 0)
        return 0;
    }
  }
  return 1;
}
int client(unsigned int x) { 
  return lib(x, 0); 
}