#ifndef EXCEPT_H
#define EXCEPT_H

#include <setjmp.h>
#define T Except_T
typedef struct T {
    const char *reason;
} T;

#undef T


#endif
