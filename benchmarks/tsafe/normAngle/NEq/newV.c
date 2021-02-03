#include <stdio.h>
#include <math.h>
#include <stdbool.h>
double snippet (double angle) {
		double twoPi = M_PI * 2; 
		if (angle < -M_PI) {
		    return angle + M_PI ;//change
		}
		if (angle > M_PI) {
			return angle - M_PI ;//change
		}
		return angle;
	}