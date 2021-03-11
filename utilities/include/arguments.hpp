#include <string>
#include <spdlog/spdlog.h>

class Arguments
{
private:
    spdlog::level::level_enum log_level;
    std::string str_network;
    int required_hosts;
    int required_subnets;

public:
    Arguments();

    spdlog::level::level_enum get_log_level();
    std::string get_str_network();
    int get_required_hosts();
    int get_required_subnets();

    void set_log_level(spdlog::level::level_enum log_level);
    void set_str_network(std::string network);
    void set_required_hosts(int required_hosts);
    void set_required_subnets(int required_subnets);
};

Arguments* parse_arguments(int argc, char** argv);
