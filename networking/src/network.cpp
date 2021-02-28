#include <network.hpp>
#include <logging.hpp>


// External class functions definitions

std::string address_to_str(int address)
{
    std::string str_address;
    int bits = 24;
    while(bits > -1)
    {
        str_address.append(std::to_string((address >> bits) & 255));
        str_address.append((bits -= 8) > -1 ? "." : "");
    }
    return str_address;
}

// Network class definition

Network::Network() {}

void Network::print_details()
{
    logger->info("IP Address: {}/{}", address_to_str(this->address), slash);
    logger->info("Mask: {}", address_to_str(this->mask));
}

int Network::get_address()
{
    return this->address;
}

int Network::get_mask()
{
    return this->mask;
}

int Network::get_slash()
{
    return this->slash;
}

void Network::set_address(int address)
{
    this->address = address;
}

void Network::set_mask(int mask)
{
    this->mask = mask;
}

void Network::set_slash(int slash)
{
    this->slash = slash;
}
