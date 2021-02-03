#include <stdio.h>
#include <math.h>
#include <stdbool.h>
void wood(double x1, double x2, double x3, double x4) {
        if ((10.0 * (x2 - x1 * x1)) == 10.0 && (5.0 - x1) == 0.0//change
            && (sqrt(64) * (x4 - x3 * x3)) == 0.0
            && (2.0 - x3) == 0.0) {
          printf("%s\n","Solved Wood constraint");
        }
    }