#include <network.hpp>
#include <logging.hpp>
#include <regex>
#include <vector>

#define NET_PATTERN "([0-9]+(.)){3}[0-9]+/[0-9]+"


Network::Network(std::string network)
{
    this->network = network;
    validate_network();
    this->address = parse_address();
    this->mask = parse_mask();
    print_details();
}

void Network::validate_network()
{
    logger->trace("Validating the [{}] string network...", network);
    std::regex pattern(NET_PATTERN);
    if (!std::regex_match(network, pattern))
    {
        logger->error("Error parsing network [{}]", network);
        exit(1);
    }
    logger->trace("Network string [{}] OK", network);
}

int Network::parse_address()
{
    logger->trace("Parsing address to integer...");
    int from_index = 0, point_index = 0;
    int address = 0, segment = 24, value;
    while (point_index >= 0)
    {
        point_index = network.find(".", from_index);
        value = atoi(network.substr(from_index, point_index).c_str());
        logger->debug("value={}, from_index={}, point_pos={}", value, from_index, point_index);

        address |= value << segment;
        segment -= 8;
        from_index = point_index + 1;
    }
    return address;
}

int Network::parse_mask()
{
    logger->trace("Parsing slash value...");
    int slash_index = network.find("/") + 1;
    logger->debug("slash_index={}", slash_index);
    this->slash = atoi(network.substr(slash_index).c_str());
    logger->debug("slash_value={}", slash);

    logger->trace("Parsing slash value to mask integer...");
    int mask = 0;
    int bits = 0;
    while(bits < slash)
        mask |= 1 << bits;
    return mask;
}

std::string Network::address_to_str(int address)
{
    std::string str_address;
    int bits = 24;
    while(bits > -1)
    {
        str_address.append(std::to_string((address >> bits) & 255));
        str_address.append((bits -= 8) > -1 ? "." : " ");
    }
    return str_address;
}

void Network::print_details()
{
    std::string output = "NETWORK DETAILS\n";
    output.append("IP Address: {}, Mask: {}");
    logger->info(output.c_str(), address_to_str(this->address), address_to_str(this->mask));
}