#include <spdlog/spdlog.h>

inline std::shared_ptr<spdlog::logger> logger;


void activate_logging(spdlog::level::level_enum log_level);
spdlog::level::level_enum str_tenum(std::string str_log_level);