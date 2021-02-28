#include <string>
#include <spdlog/spdlog.h>

class Arguments
{
private:
    spdlog::level::level_enum log_level;
    std::string network;

public:
    Arguments();

    spdlog::level::level_enum get_log_level();
    void set_log_level(spdlog::level::level_enum log_level);

    std::string get_network();
    void set_network(std::string network);
};

Arguments* parse_arguments(int argc, char** argv);
