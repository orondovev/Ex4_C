CC=gcc
OBJECTS_MAIN=main.o
FLAGS= -Wall -g

all: graph

graph: $(OBJECTS_MAIN) graph.o
	$(CC) $(FLAGS) -o graph  $(OBJECTS_MAIN) graph.o

$(OBJECTS_MAIN): main.c graph.h
	$(CC) $(FLAGS) -c graph.c

.PHONY: clean all

clean:
	rm -f *.o graph