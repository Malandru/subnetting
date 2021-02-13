#include <logging.hpp>
#include <argsparse.hpp>

void activate_logging()
{
    // create color multi threaded logger
    logger = spdlog::stdout_color_mt("console");
    logger->set_pattern("[%d-%b-%Y %T] [%l] %v");

    if (FLAGS_trace)
        logger->set_level(spdlog::level::trace);
    else if (FLAGS_debug)
        logger->set_level(spdlog::level::debug);
    else if (FLAGS_info)
        logger->set_level(spdlog::level::info);
    else if (FLAGS_warn)
        logger->set_level(spdlog::level::warn);
    else if (FLAGS_error)
        logger->set_level(spdlog::level::err);
    else if (FLAGS_critical)
        logger->set_level(spdlog::level::critical);
    else if (FLAGS_off)
        logger->set_level(spdlog::level::off);
    else
        logger->set_level(spdlog::level::info);
    
    logger->info("Logger activated");
}
