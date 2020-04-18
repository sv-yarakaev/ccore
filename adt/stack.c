#include <stddef.h>
#include "assert.h"
#include "mem.h"
#include "stack.h"

#define T Stack_T

struct T {
    int count;
    struct elem {
        void *x;
        struct elem *link;
    } *head;
};

T Stack_new(void) {
    T stk;
    NEW(stk);
    stk->count = 0;
    stk->head = NULL;
    return stk;
}

int Stack_empty(T stk) {
    assert(stk);
    return stk->count == 0;
}


