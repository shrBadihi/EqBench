#include <stdio.h>
#include <math.h>
#include <stdbool.h>
double snippet (double angle) {
		double twoPi = M_PI * 2; 
    if (angle < -twoPi/2) {//change
      return angle + M_PI * 2; //change
		}
		if (angle > M_PI) {
			return angle - twoPi;
		}
		return angle;
	}