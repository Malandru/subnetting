#include <math.h>
#include <stdio.h>
#include <tools.h>
#include <string.h>

struct Options options;

int n, m, r;
int new_mask;
int beg, t_sbnts;

void print_network(int address, int slash=0);
void subnet(int, int, int);

int main(int argc, char **argv)
{
    try
    {
        analyze(argc, argv, options);
    }catch(const char *error)
    {
        printf("%s", error);
        exit(1);
    }
    // show_options(options);
    int address = read_address(options.network);
    int slash = read_slash(options.network);
    int mask = get_mask(slash);
    printf("-------------------------------------------------------------------\n");
    printf("\t\t\tNetwork information\n");
    printf("Address: ");
    print_network(address, slash);
    printf("Old mask: ");
    print_network(mask);
    // int address = 192 << 24 | 168 << 16 | 1 << 8 | 0;
    // int mask = 255 << 24 | 255 << 16 | 255 << 8 | 0;
    // print_network(address, get_slash(mask));
    // print_network(mask);
    subnet(address, mask, options.needed);
    return 0;
}

//////////////// SUBNET FUNCTIONS /////////////////////
void print_network(int address, int slash)
{
    int bits = 24;
    while(bits > -1)
    {
	    printf("%d", (address >> bits) & 255);
	    printf( (bits -= 8) > -1 ? "." : " ");
    }
    printf(slash ? "/ %d\n" : "\n", slash);
}

void subnet(int address, int old_mask, int needed)
{
    if(options.by_hosts) //Ask which method to use
        needed += 2;
    n = ceil(log2(needed)); //Bits borrowed
    m = 32 - get_slash(old_mask) - n;
    //Getting the new subnet mask
    new_mask = (old_mask >> m) | old_mask;
    printf("New mask: ");
    print_network(new_mask);
    //Getting total of subnets
    t_sbnts = pow(2, m);
    //Asks how many subnets will be printed
    if(options.list == NOT_SET)
        options.list = t_sbnts;
    //This flag is used to know where to start printing
    beg = 0; r = 1;
    if(options.reverse)
    {
        m = (old_mask ^ new_mask);
        r = -1; //Used to substract (m - iteration)
    }
    else m = 0;
    //From binary to integer (abstract interpretation)
    new_mask = get_slash(new_mask);
    //If enumerate option is setted
    const char *x;
    options.enum_ ? x = ENUM : x = NO_ENUM;
    //Ready to start printing
    printf("-------------------------------------------------------------------\n");
    while(beg < t_sbnts)
    {
        printf(x, beg);
        print_network(address | (m + r * (beg++ << n)), new_mask);
    }
}