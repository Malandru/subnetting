#include <arguments.hpp>
#include <argparse.hpp>
#include <logging.hpp>
#include <iostream>


// Arguments class definitions

Arguments::Arguments(){}

spdlog::level::level_enum Arguments::get_log_level()
{
    return this->log_level;
}

void Arguments::set_log_level(spdlog::level::level_enum log_level)
{
    this->log_level = log_level;
}

std::string Arguments::get_network()
{
    return this->network;
}

void Arguments::set_network(std::string network)
{
    this->network = network;
}


// Other functions definitions

Arguments* parse_arguments(int argc, char** argv)
{
    argparse::ArgumentParser program("subnet");

    program.add_argument("-l", "--level")
        .help("Log level (trace, info, debug, error, critical), default is --level info")
        .default_value(std::string("info"));

    program.add_argument("network")
        .required()
        .help("network segment, for example 192.168.1.1/24 ");

    try
    {
        program.parse_args(argc, argv);
    }
    catch (const std::runtime_error &err)
    {
        std::cout << err.what() << std::endl;
        std::cout << program;
        exit(0);
    }

    // At this point, the parse was OK, so we get the arguments data
    std::string log_level = program.get<std::string>("--level");
    std::string network = program.get<std::string>("network");


    Arguments* arguments = new Arguments();
    arguments->set_network(network);
    arguments->set_log_level(str_tenum(log_level));

    return arguments;
}