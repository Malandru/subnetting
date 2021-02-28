#include <logging.hpp>
#include <argparse.hpp>

#include <network.hpp>
#include <iostream>
#include <stdlib.h>

int main(int argc, char **argv)
{
    argparse::ArgumentParser program("subnet");

    program.add_argument("-c", "--config")
        .help("Configuration input JSON file")
        .default_value(std::string("config.json"));

    program.add_argument("-m", "--models_dir")
        .help("Models directory")
        .default_value(std::string("."));

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
    std::cout << "Everything is OK" << std::endl;

    std::string config = program.get<std::string>("--config");
    std::string models_dir = program.get<std::string>("--models_dir");

    char* output;
    output = realpath(config.c_str(), NULL);
    if (output == NULL)
        std::cout << "Configuration file does not exist" << std::endl;
    else
        config.assign(output);
    
    output = realpath(models_dir.c_str(), NULL);
    if (output == NULL)
        std::cout << "Models directory does not exist" << std::endl;
    else
        models_dir.assign(output);


    std::cout << "Configuration file: " << config << std::endl;
    std::cout << "Models directory: " << models_dir << std::endl;
    return 0;
}