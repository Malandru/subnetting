# subnet-command
Basic IPv4 subnet calculator developed with C++

## Execution

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

It uses bitwise operations to calculate the new addresses, so it is fast getting results.
```
$ ./subnet --subnets 1000 172.16.0.0/16

[dd-mm-yyyy HH:MM:ss] [info] IP Address: 172.16.0.0/16
[dd-mm-yyyy HH:MM:ss] [info] Mask: 255.255.0.0

[dd-mm-yyyy HH:MM:ss] [info] Total of subnets: 1024
[dd-mm-yyyy HH:MM:ss] [info] Hosts per new network: 62
	IPv4 subnet by required networks results
--------------------------------------------
ID	Network Address		Full mask address	Broadcast
0	172.16.0.0	/26	255.255.255.192		172.16.0.63
1	172.16.0.64	/26	255.255.255.192		172.16.0.127
2	172.16.0.128	/26	255.255.255.192		172.16.0.191
...
1020	172.16.255.0	/26	255.255.255.192		172.16.255.63
1021	172.16.255.64	/26	255.255.255.192		172.16.255.127
1022	172.16.255.128	/26	255.255.255.192		172.16.255.191
1023	172.16.255.192	/26	255.255.255.192		172.16.255.255
--------------------------------------------

```

## Requirements
If you want to compile it in your system, there are some tools that you need to install before compilation
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

* Download the [argparse.hpp](https://github.com/p-ranav/argparse/releases/tag/v2.0) file from Nov 21, 2019 release, then run:
```
sudo cp ~/Downloads/argparse.hpp /usr/include/
```

## Compilation
* Clone the `subnetting` repository
```
git clone https://github.com/Malandru/subnetting
```
* Create an empty folder inside the `subnetting/` project to generate the executable
```
mkdir subnetting/build
cd subnetting/build
```
* Compile the code
```
cmake ..  # inside subnetting/build/
make
```
