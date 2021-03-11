#!/bin/sh

echo ">> Checking if g++ is installed"
if command -v g++
then
    g++ --version
else
    sudo apt-get install build-essentials
fi

echo ">> Checking if cmake is installed"
if command -v cmake; then
    cmake --version
else
    sudo apt-get install cmake
fi

echo ">> Checking if argparse is installed"
argparse=/usr/include/argparse.hpp
if test -f "$argparse"; then
    echo "$argparse OK!"
else
    echo "Downloading argparse.hpp from https://github.com/p-ranav/argparse/releases/tag/v2.0"
    wget https://github.com/p-ranav/argparse/releases/download/v2.0/argparse.hpp --quiet
    sudo mv argparse.hpp /usr/include/
    echo "Done!"
fi

echo ">> Checking if libspdlog-dev is installed"
spdlog=/usr/include/spdlog/
if test -d "$spdlog"; then
    echo "$spdlog OK!"
else
    sudo apt-get install libspdlog-dev
fi
