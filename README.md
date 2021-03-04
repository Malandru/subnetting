# subnet-command
A program that works like a terminal command.

It subnets a Network by a number of required hosts or a number of required networks.
 
## Requirements

### build-essentials
```
sudo apt-get install build-essentials
g++ --version
```
### cmake
```
sudo apt-get install cmake
cmake --version
```
### The [spdlog](https://github.com/gabime/spdlog) library
```
sudo apt-get install libspdlog-dev
```
### The [p-ranav/argparse](https://github.com/p-ranav/argparse) header file

* Download the [argparse.hpp](https://github.com/p-ranav/argparse/releases/tag/v2.0) file from Nov 21, 2019 release
```
sudo cp ~/Downloads/argparse.hpp /usr/include/
```

## Compilation
* Clone the repository
```
git clone https://github.com/Malandru/subnetting
```
* Create an empty folder to generate the executable
```
mkdir subnetting/build
cd subnetting/build
```
* Compile the code
```
cmake ..  # inside subnetting/build/
make
```

## Execution
Inside `subnetting/build/` directory:

```
$ ./subnet --help

help called
Usage: subnet [options] network 

Positional arguments:
network         network segment, for example 192.168.1.1/24 [Required]

Optional arguments:
-h --help       show this help message and exit
-l --level      Log level (trace, info, debug, error, critical), default is --level info
--hosts         Required hosts to implement the subnetting
--subnets       Required subnets to implement the subnetting
```


Usage examples:
```
$ ./subnet --hosts 120 192.168.1.0/24

[dd-mm-yyyy HH:MM:ss] [info] IP Address: 192.168.1.0/24
[dd-mm-yyyy HH:MM:ss] [info] Mask: 255.255.255.0

[dd-mm-yyyy HH:MM:ss] [info] Total of subnets: 2
[dd-mm-yyyy HH:MM:ss] [info] Hosts per new network: 126
        IPv4 subnet by required hosts results
--------------------------------------------
ID      Network Address         Full mask address       Broadcast
0       192.168.1.0     /25     255.255.255.128         192.168.1.127
1       192.168.1.128   /25     255.255.255.128         192.168.1.255
--------------------------------------------

```
```
$ ./subnet --subnets 4 192.168.1.0/24

[dd-mm-yyyy HH:MM:ss] [info] IP Address: 192.168.1.0/24
[dd-mm-yyyy HH:MM:ss] [info] Mask: 255.255.255.0

[dd-mm-yyyy HH:MM:ss] [info] Total of subnets: 4
[dd-mm-yyyy HH:MM:ss] [info] Hosts per new network: 62
        IPv4 subnet by required networks results
--------------------------------------------
ID      Network Address         Full mask address       Broadcast
0       192.168.1.0     /26     255.255.255.192         192.168.1.63
1       192.168.1.64    /26     255.255.255.192         192.168.1.127
2       192.168.1.128   /26     255.255.255.192         192.168.1.191
3       192.168.1.192   /26     255.255.255.192         192.168.1.255
--------------------------------------------

```
