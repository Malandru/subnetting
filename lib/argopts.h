#include <stdio.h>

int get_slash(int mask)
{
    int k = 0;
    while( !( (mask >> k) & 1 ) )
        k++;
    return 32 - k;
}

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