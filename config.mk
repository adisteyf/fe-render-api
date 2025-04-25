# See LICENSE for more details
# fe-render-api - reder API for FilesEngine
# ---
# Customize your build here

CC = tcc
STD = c99
OPTIMIZE = -g

PKG_CONFIG = pkg-config
INCS = -Iinclude
LIBS = -Llib \
	`${PKG_CONFIG} --libs glfw3` \
	`${PKG_CONFIG} --libs gl`


CFLAGS = ${INCS} ${LIBS} -Wall -std=${STD} ${OPTIMIZE}
