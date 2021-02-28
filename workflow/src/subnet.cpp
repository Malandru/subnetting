#include <subnet.hpp>
#include <logging.hpp>
#include <math.h>

std::vector<Network*> subnet(Network* base, int required_subnets)
{
    std::vector<Network*> subnets;
    int borrowed_bits = ceil(log2(required_subnets));  // borrowed from network bits
    int new_slash = base->get_slash() + borrowed_bits;
    int host_bits = IPV4_NET_BITS - new_slash;

    if (new_slash >= IPV4_NET_BITS)
    {
        logger->error("Can not create {} subnets because {} bits are required, but only {} are available", 
            required_subnets, borrowed_bits, IPV4_NET_BITS - base->get_slash());
        exit(1);
    }

    int total_subnets = pow(2, borrowed_bits);
    int hosts_per_net = pow(2, host_bits) - 2;  // minus the initial address and the final address

    logger->debug("Borrowed bits: {}", borrowed_bits);
    logger->debug("New slash (network bits): {}", new_slash);
    logger->debug("Host bits: {}", host_bits);
    logger->info("Total of subnets: {}", total_subnets);
    logger->info("Hosts per new network: {}", hosts_per_net);

    int new_mask = base->get_mask() | (base->get_mask() >> borrowed_bits);
    int new_address;

    Network* network;
    for (int i = 0; i < total_subnets; i++)
    {
        new_address = base->get_address() | (i << host_bits);
        new_address = new_address & new_mask;

        network = new Network();
        network->set_address(new_address);
        network->set_mask(new_mask);
        network->set_slash(new_slash);

        subnets.push_back(network);
    }

    return subnets;
}

std::vector<Network*> subnet_by_hosts(Network* base, int required_hosts)
{
    int host_bits = ceil(log2(required_hosts + 2));
    int borrowed_bits = IPV4_NET_BITS - (base->get_slash() + host_bits);
    int required_subnets = pow(2, borrowed_bits);

    if (borrowed_bits < 0)
    {
        int max_hosts = pow(2, IPV4_NET_BITS - base->get_slash());
        logger->error("Max hosts per network are {}, but you're asking for [{}]",
            max_hosts, required_hosts);
        exit(1);
    }

    return subnet(base, required_subnets);
}