

CC = g++
FLAGS = -std=c++11 -g

SOURCES := $(wildcard t*.cpp)

EXECUTABLES = $(SOURCES:.cpp=)

all: $(EXECUTABLES)

% : %.cpp macros.h test_funcs.h pqueue.h
	$(CC) $(FLAGS)  $< -o $@

clean:
	rm -f $(EXECUTABLES)

