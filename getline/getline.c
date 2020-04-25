#define _GNU_SOURCE 1
#include <stdio.h>
#include <sys/types.h>


int main(void) {
    char *line = NULL;
    size_t size = 0;
    ssize_t ret;
    while((ret = getline(&line, &size, stdin)) != -1) {
        printf("(%lu) %s", size, line);
    }
    return 0;
}

