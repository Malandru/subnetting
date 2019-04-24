#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <tools.h>

int get_slash(int mask)
{
    int k = 0;
    while(!((mask >> k++) & 1));
    return 32 - k;
}

void analyze(int argc, char **argv, struct Options &options)
{
    int option;
    bool ok = false;
    while((option = getopt(argc, argv, "h:s:l:aern:")) > 0)
        switch(option)
        {
            case 'a':
                options.list_all = true;
                break;
            case 'e':
                options.enum_ = true;
                break;
            case 'r':
                options.reverse = true;
                break;
            case 'n':
                options.network = optarg;
                ok = options.by_hosts | options.by_subnets;
                break;
            case 'h':
                if(options.by_subnets)
                    throw ERROR;
                options.by_hosts = true;
                options.needed = atoi(optarg);
                break;
            case 's':
                if(options.by_hosts)
                    throw ERROR;
                options.by_subnets = true;
                options.needed = atoi(optarg);
                break;
            case 'l':
                options.list = atoi(optarg);
                break;
            default:
                throw ERROR;
                break;
        }
    if(!ok)
        throw ERROR;
}

void show_options(struct Options options)
{
    printf("By hosts: %d\n", options.by_hosts);
    printf("By subnets: %d\n", options.by_subnets);
    printf("Reverse: %d\n", options.reverse);
    printf("Enum: %d\n", options.enum_);
    printf("List all: %d\n", options.list_all);

    printf("List: %d\n", options.list);
    printf("Needed: %d\n", options.needed);
    printf("Network: %s\n", options.network);
}