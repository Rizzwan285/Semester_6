#ifndef MACROLIB_H
#define MACROLIB_H

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define IS_EVEN(n) (((n) % 2) == 0)
#define IN_RANGE(v,lo,hi) ((v) >= (lo) && (v) <= (hi))

#define CLAMP(v,lo,hi) ((v) < (lo) ? (lo) : ((v) > (hi) ? (hi) : (v)))

#endif