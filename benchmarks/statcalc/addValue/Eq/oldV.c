#include <stdio.h>
#include <math.h>
#include <stdbool.h>
double sum = 0;
double sumOfSquares = 0;
double mean = 0;
double deviation = 0;
int count = 0;
void addValue(double val)
{
  count++;
  printf("%s\n","stat ");
  double currentVal = val;
  sum += currentVal;
  sumOfSquares += currentVal * currentVal;
  mean = sum / count;
  deviation = sqrt( (sumOfSquares / count) - (mean * mean) );
}