# See LICENSE for more details
# fe-render-api - reder API for FilesEngine
# ---
# Customize your build here

CC = cc
STD = c99
OPTIMIZE = -O2
SOBUILDFLAGS = -L. -lfe-render-api -Wl,-rpath,.
BUILDFLAGS = ${SOBUILDFLAGS}

PKG_CONFIG = pkg-config
INCS = -Iinclude
LIBS = -Llib \
	`${PKG_CONFIG} --libs glfw3` \
	`${PKG_CONFIG} --libs gl`


CFLAGS = ${INCS} ${LIBS} -Wall -std=${STD} ${OPTIMIZE}
