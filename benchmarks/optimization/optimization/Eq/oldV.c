#include <stdio.h>
#include <math.h>
#include <stdbool.h>
const double theta(double x1, double x2) {
    if(x1 > 0.0) {
      return atan(x2 / x1) / (2 * M_PI);
    } else if (x1 < 0.0) {
      return (atan(x2 / x1) / (2 * M_PI) + 0.5);
    }
    return 0.0;
}
void wood(double x1, double x2, double x3, double x4) {
        if ((10.0 * (x2 - x1 * x1)) == 0.0 && (5.0 - x1) == 0.0
            && (sqrt(64) * (x4 - x3 * x3)) == 0.0
            && (2.0 - x3) == 0.0) {
          printf("%s\n","Solved Wood constraint");
        }
    }