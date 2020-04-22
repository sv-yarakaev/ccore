#include <stdio.h>
#include <getopt.h> /* GLIBC */
#include <unistd.h>

int getopt_long(int argc, char *const argv[], const char *optstring,
        const struct option *longopts, int *longindex);
int getopt_long_only(int argc, char *const argv[],
        const char *optstring,
        const struct option *longopts, int *longindex);

/* 
 * Fist three arguments is the same  as  in getopt(). Next option is pointer to array struct option,
 * then me call "table of long options"
 * */
int do_all, do_help, do_verbose;
char *myfile;

struct option longopts[] = {
    {"all", no_argument, &do_all, 1 },
    {"file", required_argument, NULL, 'f'},
    {"help", no_argument, &do_help, 1 },
    {"verbose", no_argument, &do_verbose, 1},
    {0, 0, 0, 0 }
};

int main(int argc, char *argv[]) {
    int oc;
    char c;
    char *b_opt_arg;
    while ((oc = getopt_long(argc, argv, ":f:", longopts, NULL)) != -1 ) {
        switch (oc) {
        case 'f':
            myfile = optarg;
            break;
        case 0:
            break;
        }
    }
    
    }

    return 0;
}
