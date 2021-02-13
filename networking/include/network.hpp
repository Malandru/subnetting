#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <string>

class Network
{
private:
    int address;
    int slash;
    int mask;

public:
    Network(std::string network);
    void print_details();
};

#endif