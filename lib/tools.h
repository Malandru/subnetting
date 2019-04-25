#define NOT_SET -1
#define ENUM "%d.-"
#define NO_ENUM ""
#define ERROR "Usage: subnet -{h|s} needed [aer] -n address/mask\n"

struct Options
{
    bool enum_;
    bool reverse;
    bool list_all;
    bool by_hosts;
    bool by_subnets;
    char *network;
    int needed;
    int list;
};

int get_slash(int);
int get_mask(int);
int read_slash(char*);
int read_address(char*);
void analyze(int, char**, struct Options&);
void show_options(struct Options);