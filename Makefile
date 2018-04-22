CC=cc -std=c99
CFLAGS=-Wall -O2
CPPFLAGS=-Imlib
PREFIX=/usr/local
RM=rm -f
MKDIR=mkdir -p
AR=ar cru
RANLIB=ranlib
MLIB_URL=https://github.com/P-p-H-d/mlib.git

.PHONY: all test check doc clean distclean depend depend.png install

all: libcallperf.a

libcallperf.a: libcallperf.c libcallperf.h mlib
	$(CC) $(CFLAGS) $(CPPFLAGS) -c libcallperf.c -o libcallperf.o
	$(AR) libcallperf.a libcallperf.o
	$(RANLIB) libcallperf.a

mlib:
	git clone $(MLIB_URL)

test:	check
check: test.c libcallperf.a
	$(CC) $(CFLAGS) test.c libcallperf.a -o test.exe
	./test.exe

doc:	README.md
	markdown < README.md > README.html

clean:
	$(RM) -f README.html *~ *.o *.a *.exe a.out

distclean: clean
	$(RM) -rf mlib


install:
	$(MKDIR) $(DESTDIR)$(PREFIX)/include
	cp libcallperf.h $(DESTDIR)$(PREFIX)/include
	$(MKDIR) $(DESTDIR)$(PREFIX)/lib
	cp libcallperf.a $(DESTDIR)$(PREFIX)/lib

