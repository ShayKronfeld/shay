CFLAGS = -Wall -g
CC = gcc
AR = ar
FP = -fPIC

.PHONY: all clean

all: my_graph knapsack

my_graph: my_graph.o libmy_mat.a
	$(CC) -o my_graph my_graph.o libmy_mat.a $(CFLAGS)

knapsack: my_Knapsack.o
	$(CC) -o knapsack my_Knapsack.o $(CFLAGS)

my_graph.o: my_graph.c my_mat.h
	$(CC) $(CFLAGS) $(FP) -c my_graph.c -o my_graph.o

libmy_mat.a: my_mat.o
	$(AR) -rcs libmy_mat.a my_mat.o 

my_mat.o: my_mat.c my_mat.h
	$(CC) $(CFLAGS) $(FP) -c my_mat.c -o my_mat.o

my_Knapsack.o: my_Knapsack.c
	$(CC) $(CFLAGS) $(FP) -c my_Knapsack.c -o my_Knapsack.o

clean: 
	rm -f *.o *.a my_graph knapsack
