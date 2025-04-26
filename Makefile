# contrib-msg
# Contributor: Adisteyf (adk.)
# Description: Script for Makefile build.
.POSIX:

include config.mk
SRC = $(wildcard src/*.c)

all: libfe-render-api.so
config.mk:
	cp config.def.mk config.mk

libfe-render-api.so: ${SRC} clean
	${CC} -fPIC -shared -o $@ ${SRC} ${CFLAGS}

clean:
	rm -f libfe-render-api.so

test-clean:
	rm -f tests/testGreetings

test: test-clean
	ls libfe-render-api.so
	@echo "Running tests..."

	${CC} tests/testGreetings.c -o tests/testGreetings ${BUILDFLAGS} ${INCS}
	./tests/testGreetings

.PHONY: all clean config.mk test test-clean

