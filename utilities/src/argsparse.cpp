#include <argsparse.hpp>

DEFINE_bool(trace, false, "");
DEFINE_bool(debug, false, "");
DEFINE_bool(info, false, "");

DEFINE_bool(warn, false, "");
DEFINE_bool(error, false, "");
DEFINE_bool(critical, false, "");

DEFINE_bool(off, false, "");

DEFINE_string(network, "", "");