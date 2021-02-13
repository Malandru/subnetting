#include <argsparse.hpp>
#include <logging.hpp>

#include <network.hpp>

int main(int argc, char** argv)
{
    gflags::ParseCommandLineFlags(&argc, &argv, true);
    activate_logging();

    Network* network = new Network(FLAGS_network);
    network->print_details();
    return 0;
}