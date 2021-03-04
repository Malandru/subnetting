#include <calculator.hpp>
#include <logging.hpp>
#include <math.h>

Calculator::Calculator(Network* base)
{
    this->base = base;
}

std::vector<Network*> Calculator::subnet_by_networks(int required)
{
    int borrowed_bits = ceil(log2(required));
    return subnetting(borrowed_bits);
}

std::vector<Network*> Calculator::subnet_by_hosts(int required)
{
    int host_bits = ceil(log2(required + 2));
    int borrowed_bits = IPV4_NET_BITS - (base->get_slash() + host_bits);
    return subnetting(borrowed_bits);
}

std::vector<Network*> Calculator::subnetting(int borrowed_bits)
{
    int new_mask = (base->get_mask() >> borrowed_bits) | base->get_mask();
    int new_slash = base->get_slash() + borrowed_bits;
    int host_bits = IPV4_NET_BITS - new_slash;

    int total_subnets = pow(2, borrowed_bits);
    int hosts_per_net = pow(2, host_bits) - 2;  // minus the network address and the broadcast address

    logger->debug("Borrowed bits: {}", borrowed_bits);
    logger->debug("New slash (network bits): {}", new_slash);
    logger->debug("Host bits: {}", host_bits);
    logger->info("Total of subnets: {}", total_subnets);
    logger->info("Hosts per new network: {}", hosts_per_net);

    int network_address;
    int network_broadcast;

    std::vector<Network*> results;
    Network* subnet;  // Will be append to the results list

    for(int i = 0; i < total_subnets; i++)
    {
        subnet = new Network();

        network_address = (i << host_bits) | base->get_address();
        network_address = new_mask & network_address;
        network_broadcast = network_address | (~new_mask);

        subnet->set_address(network_address);
        subnet->set_broadcast(network_broadcast);
        subnet->set_mask(new_mask);
        subnet->set_slash(new_slash);

        results.push_back(subnet);
    }

    return results;
}
