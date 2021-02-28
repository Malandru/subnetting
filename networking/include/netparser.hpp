#ifndef NETPARSER_HPP
#define NETPARSER_HPP
#include <network.hpp>
#include <string>

class NetParser
{
private:
    Network* network;

    void assert_network(std::string str_net);
    int parse_address(std::string str_net);
    int extract_slash(std::string str_net);
    int parse_mask(int slash);

public:
    NetParser(std::string str_net);

    Network* get_network();
};

#endif