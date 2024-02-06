CFLAGS = -Wall -g
CC = gcc
AR = ar
FP = -fPIC

.PHONY: all clean

all: mains

mains: my_graph.o libmy_mat.a
	$(CC) -o mains my_graph.o libmy_mat.a $(CFLAGS)

my_graph.o: my_graph.c my_mat.h
	$(CC) $(CFLAGS) $(FP) -c my_graph.c -o my_graph.o

libmy_mat.a: my_mat.o 
	$(AR) -rcs libmy_mat.a my_mat.o 

my_mat.o: my_mat.c my_mat.h
	$(CC) $(CFLAGS) $(FP) -c my_mat.c -o my_mat.o

clean: 
	rm -f *.o *.a mains
