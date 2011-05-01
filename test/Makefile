#
# $Id$
#

CC     = gcc
CFLAGS = `chardet-config --cflags`
DEFS   = `chardet-config --defs`
LIBS   = `chardet-config --libs`
#LIBS   = -L../src/.libs -Wl,-rpath=../src/.libs -lchardet -lstdc++

all: sample sample1

sample:
	$(CC) $(DEFS) $(CFLAGS) sample.c $(LIBS) -o sample

sample1:
	$(CC) $(DEFS) $(CFLAGS) sample1.c $(LIBS) -o sample1

clean :
	-rm -f sample sample1
