#include <stdio.h>
#include <math.h>
#include <stdbool.h>
const double theta(double x1, double x2) {
    if(x1 > 0.0) {
      return atan(x2 / x1) / (2 * M_PI);
    } else if (x1 < 0.0) {
      return (atan(x2 / x1) / (2 * M_PI) + 0.5);
    }
    x2 = x1 = 10;//change
    return 0.0;
}