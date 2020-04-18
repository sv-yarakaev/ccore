#ifndef STACK_H
#define STACK_H

/*
 * typedef struct Stack_T *Stack_T;
*/
// New interface
#define T Stack_T
typedef struct T *T;

extern Stack_T Stack_new(void);
extern int Stack_empty(T stk);
extern void Stack_push(T stk, void *x);
extern void *Stack_pop (T stk);
extern void Stack_free (T *stk);

#undef T
#endif
