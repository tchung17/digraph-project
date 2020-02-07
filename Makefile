CC = g++
CONSERVATIVE_FLAGS = -std=c++11 -Wall -Wextra -pedantic
DEBUGGING_FLAGS = -g -O0
CFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)

digraphAnalyzer: digraphAnalyzer.o digraph.o
	$(CC) $(CFLAGS) -o digraphAnalyzer digraphAnalyzer.o digraph.o

digraphAnalyzer.o: digraphAnalyzer.cpp digraph.h
	$(CC) $(CFLAGS) -c digraphAnalyzer.cpp

digraph.o: digraph.cpp digraph.h
	$(CC) $(CFLAGS) -c digraph.cpp

clean:
	rm -f *.o digraphAnalyzer

