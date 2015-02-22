
# Basic Makefile 
# all is the default target and is called when just make with
# no options is run.


#
# change this to the name you want the program to have
# DOES NOT necessarily have to be the same as any *.cpp file!
# DOES NOT have an extension
#
#	Example:
#		EXECUTABLE=main
#
EXECUTABLE=main
#
# change this to list all the *.cpp files for sources
#
#
#	Example:
#		SOURCES=main.cpp string_set.cpp
#
SOURCES=main.cpp ordered_set.cpp


#
# don't change the rest
#

CC=g++
CFLAGS=-c -Wall -g
LDFLAGS=
OBJECTS=$(SOURCES:.cpp=.o)

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@


