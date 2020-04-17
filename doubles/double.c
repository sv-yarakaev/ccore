#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>

int lineum;

void doubleword(char*, FILE *);



int main(int argc, char* argv[]) {
    int i;
   // if (argc == 1) doubleword

    for(i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            fprintf(stderr, "%s: can't open '%s' (%s)\n", argv[0], argv[i], strerror(errno));
            return EXIT_FAILURE;
        } else {
            doubleword(argv[i], fp);
            fclose(fp);
        }
    }
    return EXIT_SUCCESS;
}

void doubleword(char *name, FILE *fp) {
    char prev[128], word[128];

    lineum = 1;
    prev[0] ='\0';
    while (getword(fp, word, sizeof (word))) {
        if (isalpha(word[0] && strcmp(prev, word)==0
            <word_duplicate>
         strcpy(prev, word);
    }
}




