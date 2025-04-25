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


.PHONY: all clean config.mk
