CC=gcc
CFLAGS=-lm -Wall -I. -pthread  
LDFLAGS=-pthread
SOURCES=prime-structs.h prime-search.c prime-print.c prime-print.h
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=prime-search

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)
