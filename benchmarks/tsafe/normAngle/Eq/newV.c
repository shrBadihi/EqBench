#include <stdio.h>
#include <math.h>
#include <stdbool.h>
double snippet (double angle) {
		double temp = M_PI * 2; //change
		if (angle < -M_PI) {
			return angle + temp; //change
		}
		if (angle > M_PI) {
			return angle - temp; //change
		}
		return angle;
	}