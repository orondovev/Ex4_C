CC=gcc
OBJECTS_MAIN=main.o
FLAGS= -Wall -g

all: graph

graph: $(OBJECTS_MAIN) graph.o algo.o
	$(CC) $(FLAGS) -o graph  $(OBJECTS_MAIN) graph.o algo.o

algo.o : algo.c graph.h
	$(CC) $(FLAGS) -c algo.c

graph.o : graph.c graph.h
	$(CC) $(FLAGS) -c graph.c

$(OBJECTS_MAIN): main.c graph.h
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm -f *.o graph