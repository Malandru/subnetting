#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <network.hpp>
#include <vector>

class Calculator
{
private:
    Network* base;
    std::vector<Network*> subnetting(int borrowed_bits);

public:
    Calculator(Network* base);
    std::vector<Network*> subnet_by_networks(int required);
    std::vector<Network*> subnet_by_hosts(int required);
};

#endif