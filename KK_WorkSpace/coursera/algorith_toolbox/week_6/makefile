#g++ -pipe -O2 -std=c++14 -Wextra -Wall -o souvenir_partition souvenir_partition.cpp -lm
CC=g++
CPPFLAGS=-pipe -O2 -std=c++17 -Wextra -Wall
LIBS=-lm

souvenir_partition: souvenir_partition.cpp
	$(CC) $(CPPFLAGS) -o souvenir_partition souvenir_partition.cpp $(LIBS)


clean:
	rm -f souvenir_partition
