CC     = gcc
#CFLAGS = `chardet-config --cflags`
#DEFS   = `chardet-config --defs`
#LIBS   = `chardet-config --libs`
CFLAGS = -I../src -I../include
LIBS   = -L../src/.libs -Wl,-rpath=../src/.libs -lchardet -lstdc++

all: sample sample1 bom-test

sample: sample.c
	$(CC) $(DEFS) $(CFLAGS) $< $(LIBS) -o $@

sample1: sample1.c
	$(CC) $(DEFS) $(CFLAGS) $< $(LIBS) -o $@

bom-test: bom-test.c
	$(CC) $(DEFS) $(CFLAGS) $< $(LIBS) -o $@

clean :
	-rm -f sample sample1 bom-test
