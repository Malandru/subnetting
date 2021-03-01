#include <arguments.hpp>
#include <logging.hpp>

#include <netparser.hpp>
#include <subnet.hpp>
#include <iostream>

void show_results(std::vector<Network*> results)
{
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "IPv4 Address\tFull mask Address\tSlash mask" << std::endl;
    for(Network* net : results)
    {
        std::cout << address_to_str(net->get_address()) << "\t";
        std::cout << address_to_str(net->get_mask()) << "\t\t";
        std::cout << net->get_slash() << std::endl;
    }
    std::cout << "--------------------------------------------" << std::endl;
}

int main(int argc, char **argv)
{
    Arguments* args = parse_arguments(argc, argv);
    activate_logging(args->get_log_level());

    NetParser netparser(args->get_network());
    Network* network = netparser.get_network();
    network->print_details();

    int required_hosts = args->get_required_hosts();
    int required_subnets = args->get_required_subnets();
    if (required_subnets == 0 && required_hosts == 0)
    {
        logger->warn("Execute with the --help flag to see subnet options");
        exit(0);
    }

    std::vector<Network*> subnets;
    if (required_subnets)
    {
        subnets = subnet(network, required_subnets);
        std::cout << "\tIPv4 subnet by required networks results" << std::endl;
        show_results(subnets);
    }

    if (required_hosts)
    {
        subnets = subnet_by_hosts(network, required_hosts);
        std::cout << "\tIPv4 subnet by required hosts results" << std::endl;
        show_results(subnets);
    }

    return 0;
}