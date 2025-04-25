.POSIX:

include config.mk

SRC = src/*.c

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

	${CC} tests/testGreetings.c -o tests/testGreetings ${BUILDFLAGS}
	./tests/testGreetings

.PHONY: all clean config.mk test test-clean

