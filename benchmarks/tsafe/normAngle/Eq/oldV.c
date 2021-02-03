#include <stdio.h>
#include <math.h>
#include <stdbool.h>
double snippet (double angle) {
		double twoPi = M_PI * 2; 
		if (angle < -M_PI) {
			return angle + twoPi;
		}
		if (angle > M_PI) {
			return angle - twoPi;
		}
		return angle;
	}