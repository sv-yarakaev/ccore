#ifndef EXCEPT_H
#define EXCEPT_H

#include <setjmp.h>
#define T Except_T
typedef struct T {
    const char *reason;
} T;

#define RAISE(e) Except_raise(&(e), __FILE__, __LINE__)

void Except_raise(const T *e, const char *file, int line);




#undef T


#endif
