#ifndef MATHOPS_H
#define MATHOPS_H

double power(double base, int exp);
double average(int arr[], int n);

#define CLAMP(v, lo, hi) (((v) < (lo)) ? (lo) : ((v) > (hi) ? (hi) : (v)))

#endif