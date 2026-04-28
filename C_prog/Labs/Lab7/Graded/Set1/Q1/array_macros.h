#ifndef ARRAY_MACROS_H
#define ARRAY_MACROS_H

#define INBOUNDS(idx,size) ((((idx)>=0) && ((idx)<size)) ? 1 : 0)
#define GET_SAFE(arr,idx,size,fallback) ((INBOUNDS((idx),(size))) ? (arr)[(idx)] : (fallback))

#endif