# subnet-command
A program that works like a terminal command.

It subnets a Network by a number of required hosts or a number of required networks.
 
## Requirements

* cmake
* build-essentials
* [argparse.hpp](https://github.com/p-ranav/argparse) Nov 21, 2019 release

## Compilation

```
git clone https://github.com/Malandru/subnetting
mkdir subnetting/build
cd subnetting/build
cmake ..
make
```

## Execution
Inside `subnetting/build/ directory`:

```
./subnet --help
```
    
Usage examples:
```
./subnet --hosts 120 192.168.1.0/24
```
```
./subnet --subnets 2 192.168.1.0/24
```
