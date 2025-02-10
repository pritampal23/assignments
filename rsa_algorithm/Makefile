CC = g++
CFLAGS = -c

#Basic implementation of RSA algorithm

main: PowerMod.o primality_test.o prime_generation.o Euclidean_algo.o error.o main.o
	$(CC) main.o PowerMod.o primality_test.o prime_generation.o Euclidean_algo.o error.o -lssl -lcrypto -lntl

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp header.h
PowerMod.o: PowerMod.cpp
	$(CC) $(CFLAGS) PowerMod.cpp
primality_test.o: primality_test.cpp
	$(CC) $(CFLAGS) primality_test.cpp
prime_generation.o: prime_generation.cpp
	$(CC) $(CFLAGS) prime_generation.cpp
Euclidean_algo.o: Euclidean_algo.cpp
	$(CC) $(CFLAGS) Euclidean_algo.cpp
error.o: error.cpp
	$(CC) $(CFLAGS) error.cpp

#Clean the executables
CLEAN:
	rm -rf *.o *.ou