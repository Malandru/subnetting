#ifndef NETWORK_HPP
#define NETWORK_HPP
#include <string>
#define IPV4_NET_BITS 32

class Network
{
private:
    int address;
    int mask;
    int slash;
    int broadcast;

public:
    Network();
    void print_details();

    int get_address();
    int get_mask();
    int get_slash();
    int get_broadcast();

    void set_address(int address);
    void set_mask(int mask);
    void set_slash(int slash);
    void set_broadcast(int broadcast);
};

std::string address_to_str(int address);

#endif