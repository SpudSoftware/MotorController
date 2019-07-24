CC=g++
CFLAGS=-I
maketest:	test.cpp test.o	
	$(CC)	-Wall -pthread -o testApp2 test.cpp -lpigpio -lrt

