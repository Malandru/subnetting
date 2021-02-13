cmake_minimum_required(VERSION 3.10)
project(subnet)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads REQUIRED)

add_subdirectory(networking)
add_subdirectory(utilities)

add_executable(subnet main.cpp)
target_link_libraries(subnet network)
