#include <arguments.hpp>
#include <logging.hpp>

#include <netparser.hpp>
#include <calculator.hpp>
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

    Calculator calculator(network);

    std::vector<Network*> subnets;
    if (required_subnets)
    {
        subnets = calculator.subnet_by_networks(required_subnets);
        std::cout << "\tIPv4 subnet by required networks results" << std::endl;
        show_results(subnets);
    }

    if (required_hosts)
    {
        subnets = calculator.subnet_by_hosts(required_hosts);
        std::cout << "\tIPv4 subnet by required hosts results" << std::endl;
        show_results(subnets);
    }

    return 0;
}