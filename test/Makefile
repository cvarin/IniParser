#
# iniparser tests Makefile
#

CC      = g++
CFLAGS  = -g -I../src
LFLAGS  = -L.. -liniparser
AR	    = ar
ARFLAGS = rcv
RM      = rm -f


default: all

all: iniexample parse

iniexample: iniexample.cpp
	$(CC) $(CFLAGS) -o iniexample iniexample.cpp -I../src -L.. -liniparser

parse: parse.cpp
	$(CC) $(CFLAGS) -o parse parse.cpp -I../src -L.. -liniparser

clean veryclean:
	$(RM) iniexample example.ini parse



