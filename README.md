# subnet-command
A program that works like a terminal command.

It subnets a Network by needed hosts or needed networks.

Syntaxis:
-
    ./subnet -{h|s}=NUM [Options] Network/mask
    
Example:

    ./subnet -h=30 192.168.1.0/24
 
Forced arguments:
-
-h=NUM:
Subnet type is by a total of NUM hosts needed.

-s=NUM:
Subnet type is by a total of NUM networks needed.

Options:
-
-e:
Enum every network printed.

-l=NUM:
List a total of NUM networks

-r:
Networks will be printed in reverse order

-x:
Print extra subnetting information

Notes:
-
Not all options are available, yet.
Before execute install.sh, build-essential is needed.

    $sudo apt-get install build-essential

The file install.sh generates bin/ and obj/ directories.
You can execute de command by changing to bin/ directory and use the example above.