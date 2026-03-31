#ifndef MACROLIB_H
#define MACROLIB_H

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x) < 0 ? -(x) : (x))

#define SWAP(a,b,type) \
do {                   \
    type temp = a;     \
    a = b;             \
    b = temp;          \
} while(0)

#endif