#include <netparser.hpp>
#include <logging.hpp>
#include <regex>
#include <bitset>

#define IPV4_NET_PATTERN "([0-9]+(.)){3}[0-9]+/[0-9]+"


NetParser::NetParser(std::string str_net)
{
    assert_network(str_net);
    int address = parse_address(str_net);
    int slash = extract_slash(str_net);
    int mask = parse_mask(slash);

    Network* network = new Network();
    network->set_address(address);
    network->set_mask(mask);
    network->set_slash(slash);

    this->network = network;
}

Network* NetParser::get_network()
{
    return this->network;
}

void NetParser::assert_network(std::string str_net)
{
    logger->trace("Validating the [{}] string network...", str_net);
    std::regex pattern(IPV4_NET_PATTERN);
    if (!std::regex_match(str_net, pattern))
    {
        logger->error("Error parsing network [{}]", str_net);
        exit(1);
    }
    logger->trace("Network string [{}] OK", str_net);
}

int NetParser::parse_address(std::string str_net)
{
    logger->trace("Parsing address to integer...");
    int from_index = 0, point_index = 0;
    int address = 0, segment = 24, value;
    while (point_index >= 0)
    {
        point_index = str_net.find(".", from_index);
        value = atoi(str_net.substr(from_index, point_index).c_str());
        logger->debug("value={}, from_index={}, point_pos={}", value, from_index, point_index);

        address |= value << segment;
        segment -= 8;
        from_index = point_index + 1;
    }
    return address;
}

int NetParser::extract_slash(std::string str_net)
{
    logger->trace("Extracting slash value...");
    int slash_index = str_net.find("/") + 1;
    logger->debug("slash_index={}", slash_index);
    int slash = atoi(str_net.substr(slash_index).c_str());
    logger->debug("slash_value={}", slash);

    return slash;
}

int NetParser::parse_mask(int slash)
{
    logger->trace("Parsing slash value to mask integer bitset...");
    int empty_bits = IPV4_NET_BITS - slash;
    int mask = 0;
    int bits = 0;
    logger->debug("Number of empty bits: {}", empty_bits);
    while(bits < empty_bits)
        mask |= (1 << bits++);

    logger->debug("Mask with empty bits defined : {}", std::bitset<IPV4_NET_BITS>(mask).to_string());
    mask = ~mask;
    logger->debug("Mask with NOT operand applied: {}", std::bitset<IPV4_NET_BITS>(mask).to_string());
    return mask;
}
