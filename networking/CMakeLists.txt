file (GLOB_RECURSE CPP_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
set (HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/)

add_library(network ${CPP_FILES})
target_include_directories(network PUBLIC ${HEADERS})
target_link_libraries(network utils)