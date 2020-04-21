#ifndef EXCEPT_H
#define EXCEPT_H

#include <setjmp.h>
#define T Except_T
typedef struct T {
    const char *reason;
} T;
typedef struct Except_Frame Except_Frame;
enum { Except_entered=0, Except_raised,
    Except_handled, Except_finalized };


struct Except_Frame {
    Except_Frame *prev;
    jmp_buf env;
    const char *file;
    int line;
    const T *exception;
};

extern Except_Frame *Except_stack;


#define RAISE(e) Except_raise(&(e), __FILE__, __LINE__)
#define RERAISE Except_raise(Except_frame.exception, \
        Except_frame.file, Except_frame.line)

#define TRY do { \
    volatile int Except_flag; \
    Except_Frame Except_frame; \
    Except_frame.prev = Except_stack; \
    Except_stack = &Except_frame; \
    Except_flag = setjmp(Except_frame.env); \
    if (Except_flag == Except_entered) {

#define EXCEPT(e) \
        if (Except_flag == Except_entered) \
        Except_stack = Except_stack->prev \
        } else if (Except_frame.exception == &(e)) { \
        Except_flag = Except_handled;
#define ELSE \
            <pop if this chunk followa s 57> \
            } else { \
                Except_flag = Except_handled;
#define FINALLY \
                <pop if this chunk follows S 57> \
                } { \
                    if (Except_flag == Except_entered) \
                        Except_flag = Except_finalized;


#define END_TRY \
                    <pop if this chunk follows S 57> \
                    } if (Except_flag == Except_raised) RERAISE; \
                    } while (0)

#define RETURN switch(Except_stack = Except_stack->prev, 0) default: return


void Except_raise(const T *e, const char *file, int line);




#undef T


#endif
