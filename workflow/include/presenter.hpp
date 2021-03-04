#ifndef PRESENTER_HPP
#define PRESENTER_HPP

#include <network.hpp>
#include <vector>
#include <iostream>

void show_results(std::vector<Network*> results)
{
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "ID\tNetwork Address\t\tFull mask address\tBroadcast" << std::endl;
    Network* net;
    for(int i = 0; i < results.size(); i++)
    {
        net = results[i];
        std::cout << i << "\t";
        std::cout << address_to_str(net->get_address()) << "\t/" << net->get_slash() << "\t";
        std::cout << address_to_str(net->get_mask()) << "\t\t";
        std::cout << address_to_str(net->get_broadcast()) << std::endl;
    }
    std::cout << "--------------------------------------------\n" << std::endl;
}

#endif
