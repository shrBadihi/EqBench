#include <stdio.h>
#include <math.h>
#include <stdbool.h>
double snippet(double a, double b) {
        if (a >= 0 && b >= 0)//change
            return a;
        if (a < 0 && b < 0)//change
            return a;
        else 
            return -a;//change    
}
