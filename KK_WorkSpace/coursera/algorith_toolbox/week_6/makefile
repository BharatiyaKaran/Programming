#g++ -pipe -O2 -std=c++14 -Wextra -Wall -o souvenir_partition souvenir_partition.cpp -lm
CC=g++
CPPFLAGS=-pipe -O2 -std=c++17 -Wextra -Wall
LIBS=-lm

souvenir_partition: souvenir_partition.cpp
	$(CC) $(CPPFLAGS) -o souvenir_partition souvenir_partition.cpp $(LIBS)

max_value_arithmetic_exp: max_value_arithmetic_exp.cpp
	$(CC) $(CPPFLAGS) -o max_value_arithmetic_exp max_value_arithmetic_exp.cpp $(LIBS)

all: souvenir_partition max_value_arithmetic_exp

clean:
	rm -f souvenir_partition
	rm -f max_value_arithmetic_exp
