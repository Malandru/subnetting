#include <stdio.h>
#include <math.h>
#include <tools.h>

struct Options options;

int n, m;
int new_mask;
int beg;

void print(int address, int slash=0)
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
    n = ceil(log2(needed + 2)); //Ask which method to use
    m = 32 - get_slash(old_mask) - n;
    //Getting the new subnet mask
    new_mask = (old_mask >> m) | old_mask;

    int t_sbnts = pow(2, m); //Total of subnets

    if(options.list == NOT_SET)
        options.list = t_sbnts;

    beg = 0;
    if(options.reverse)
    {
        address = (old_mask ^ new_mask) | address;
        beg = t_sbnts;
    }

    new_mask = get_slash(new_mask);
    const char *x;
    options.enum_ ? x = ENUM : x = NO_ENUM;
    while(beg < t_sbnts)
    {
        printf(x, beg);
        print(address | (beg++ << n), new_mask);
    }

    //address = address | (___ << n);
    //Last address: 
    print(address, get_slash(new_mask));
}

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
    
    int address = 10 << 24 | 1 << 16 | 0 << 8 | 0;
    int mask = 255 << 24 | 255 << 16 | 128 << 8 | 0;
    print(address, get_slash(mask));
    print(mask);
    subnet(address, mask, 150);
    return 0;
}
