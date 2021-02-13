#include <network.hpp>
#include <logging.hpp>
#include <regex>

#define NET_PATTERN "([0-9]+(.)){3}[0-9]+/[0-9]+"


Network::Network(std::string network)
{
    logger->trace("Creating a new network: {}", network);
    std::regex pattern(NET_PATTERN);

    if(!std::regex_match(network, pattern))
    {
        logger->error("Error parsing network [{}]", network);
        exit(1);
    }
}

void Network::print_details()
{
    logger->info("Printing details");
}