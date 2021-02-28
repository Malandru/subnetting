#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <string>

class Network
{
private:
    std::string network;
    int address;
    int slash;
    int mask;

    void validate_network();
    std::string address_to_str(int address);

    int parse_address();
    int parse_mask();

public:
    Network(std::string network);
    void print_details();
};

#endif