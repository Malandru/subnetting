mkdir -p obj
mkdir -p bin
g++ -c src/tools.cpp -I lib -o obj/tools.o
g++ -c src/subnet.cpp -I lib -o obj/subnet.o
g++ obj/subnet.o obj/tools.o -o bin/subnet