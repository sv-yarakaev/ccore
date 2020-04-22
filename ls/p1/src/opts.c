#include <stdio.h>
#include <getopt.h> /* GLIBC */
#include <unistd.h>

extern char *optarg;
extern int optind, opterr, optopt;

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
char *myfile, *user;

struct option longopts[] = {
    {"all", no_argument, &do_all, 1 },
    {"file", required_argument, NULL, 'f'},
    {"help", no_argument, &do_help, 1 },
    {"verbose", no_argument, &do_verbose, 1},
    {"user", optional_argument, NULL, 'u'},
    {0, 0, 0, 0 }
};

int main(int argc, char *argv[]) {
    int oc;
    /*int c;
    char *b_opt_arg;
    */
    while ((oc = getopt_long(argc, argv, ":ahvf:u::W;", longopts, NULL)) != -1 ) {
        switch (oc) {
            case 'a':
                do_all = 1;
                break;
            case 'f':
                myfile = optarg;
                break;
            case 'h':
                do_help = 1;
                break;
            case 'u':
                if (optarg != NULL)
                    user = optarg;
                else
                    user = "root";
                break;
            case 'v':
                do_verbose = 1;
                break;
        case 0:
            break;
        case ':' :
            fprintf(stderr, "%s: option `-%c' required an argument\n",
                    argv[0], optopt);
            break;
        case '?':
        default:
            fprintf(stderr, "%s: option `-%c' is invalid: ignored\n",
                    argv[0], optopt);
            break;
        }
    }
    return 0;
}
