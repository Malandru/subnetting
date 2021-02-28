#ifndef NETWORK_HPP
#define NETWORK_HPP
#include <string>

class Network
{
private:
    int address;
    int mask;
    int slash;

public:
    Network();
    void print_details();

    int get_address();
    int get_mask();
    int get_slash();

    void set_address(int address);
    void set_mask(int mask);
    void set_slash(int slash);
};

std::string address_to_str(int address);

#endif