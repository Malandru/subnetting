cmake_minimum_required(VERSION 3.10)
project(subnet)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads REQUIRED)

if (APPLE)
    message("Using macOS C++ flags")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -static-libstdc++")
else()
    message("Using Linux g++ flags")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
endif()

include_directories(thirdparty)

add_subdirectory(networking)
add_subdirectory(utilities)
add_subdirectory(workflow)

add_executable(subnet main.cpp)
target_link_libraries(subnet wflow)
