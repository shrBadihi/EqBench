#include <stdio.h>
#include <math.h>
#include <stdbool.h>
double snippet(double a, double b) {
        if (b >= 0){
            if (a >= 0)
                return a;
            else
                return -a;
        }
        else {
            if (a >= 0)
                return -a;
            else
                return a;
        }
}