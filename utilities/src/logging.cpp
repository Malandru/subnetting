#include <logging.hpp>
#define TRACE "trace"
#define DEBUG "debug"
#define INFO "info"
#define WARN "warn"
#define ERROR "error"
#define CRITICAL "critical"


void activate_logging(spdlog::level::level_enum log_level)
{
    // create color multi threaded logger
    logger = spdlog::stdout_color_mt("console");
    logger->set_pattern("[%d-%b-%Y %T] [%l] %v");
    logger->set_level(log_level);
    logger->trace("Global logger activated");
}

spdlog::level::level_enum str_tenum(std::string str_log_level)
{
    if (str_log_level == TRACE)
        return spdlog::level::level_enum::trace;
    if (str_log_level == DEBUG)
        return spdlog::level::level_enum::debug;
    if (str_log_level == INFO)
        return spdlog::level::level_enum::info;
    if (str_log_level == WARN)
        return spdlog::level::level_enum::warn;
    if (str_log_level == ERROR)
        return spdlog::level::level_enum::err;
    if (str_log_level == CRITICAL)
        return spdlog::level::level_enum::critical;

    return spdlog::level::level_enum::info;
}
