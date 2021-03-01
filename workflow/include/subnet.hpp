#ifndef SUBNET_HPP
#define SUBNET_HPP

#include <network.hpp>
#include <vector>

std::vector<Network*> subnet_by_hosts(Network* base, int required_hosts);
std::vector<Network*> subnet(Network* base, int required_subnets);

#endif