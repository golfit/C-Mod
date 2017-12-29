CC=gcc
INCLU=-I/usr/local/mdsplus/include
FLAGS=$(INCL) -L/usr/local/mdsplus/lib \
 -lMdsLib_client -g

all: example

# Note that Makefiles need tabs for separators, and four spaces don't equal a tab.  Wow.
example: test_mdsplus.c
	$(CC) $(FLAGS) test_mdsplus.c -o test_mdsplus

clean:
	rm -f *! core a.out test_mdsplus *.o
