#include <stdio.h>
#include <unistd.h>

int getopt(int argc, char *const argv[], const char *optstring);
extern char *optarg;
extern int optind, opterr, optopt;

int main(int argc, char *argv[]) {
    int oc;
    char *b_opt_arg;
    while ((oc = getopt(argc, argv, "ab:")) != -1 ) {
        switch (oc) {
            case 'a':
                printf("Parsing a optins\n");
                break;
            case 'b':
                b_opt_arg = optarg;
                printf("Parsing -b with arg %s\n", b_opt_arg);
                break;
            case ':':
                printf("Maybe some error\n");
            case '?' :
            default:
                return -1;
        }
    }
    return 0;
}
