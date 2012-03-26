#
# iniparser Makefile
#

# Compiler settings
CC      = g++
CFLAGS  = -O2 -fPIC -Wall -ansi -pedantic

# Ar settings to build the library
AR	    = ar
ARFLAGS = rcv

SHLD = ${CC} ${CFLAGS}
LDSHFLAGS = -shared -Wl,-Bsymbolic  -Wl,-rpath -Wl,/usr/lib -Wl,-rpath,/usr/lib
LDFLAGS = -Wl,-rpath -Wl,/usr/lib -Wl,-rpath,/usr/lib

# Set RANLIB to ranlib on systems that require it (Sun OS < 4, Mac OSX)
# RANLIB  = ranlib
RANLIB = true

RM      = rm -f

SRCS = src/iniparser.cpp \
	   src/IniParser.cpp
OBJS = $(SRCS:.cpp=.o)
HEADS = $(SRCS:.cpp=.hpp)

# Implicit rules

COMPILE.cpp=$(CC) $(CFLAGS) -c
%.o: %.cpp $(HEADS)
	@(echo "compiling $< ...")
	@($(COMPILE.cpp) -o $@ $<)

default:	libiniparser.a libiniparser.so

libiniparser.a:	$(OBJS) $(HEADS)
	@($(AR) $(ARFLAGS) libiniparser.a $(OBJS))
	@($(RANLIB) libiniparser.a)

libiniparser.so:	$(OBJS) $(HEADS)
	@$(SHLD) $(LDSHFLAGS) -o $@.0 $(OBJS) $(LDFLAGS) \
		-Wl,-soname=`basename $@`.0

clean:
	$(RM) $(OBJS)

clean_all ca:
	$(RM) $(OBJS) libiniparser.a libiniparser.so*
	cd test ; $(MAKE) veryclean

veryclean:
	$(RM) $(OBJS) libiniparser.a libiniparser.so*
	rm -rf ./html ; mkdir html
	cd test ; $(MAKE) veryclean

docs:
	@(cd doc ; $(MAKE))
	
check:
	@(cd test ; $(MAKE))
