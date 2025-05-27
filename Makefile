# Target
TARGET=				warm

# Compilers
CC=					clang

# Directories
INCDIRS=			-I. -I./include 
LIBDIRS=			

# Libraries
LDLIBS=				

# Flags
DEBUG=				-g3 -O0 -DTESTING
C_WARN=				-Wall -Wextra -Werror -Wpedantic
C_STD=				-ansi

# Combined flags
CFLAGS=				${INCDIRS} ${DEBUG} ${C_WARN} ${C_STD}
LDFLAGS=			${LIBDIRS} ${DEBUG} ${LDLIBS}

# Sources and Objects
SRCS=				main.c dot.c
OBJS=				${SRCS:.c=.o}

# Default target
all: ${TARGET}
	@echo "all"

${TARGET}: ${OBJS}
	@echo "target"
	${CC} ${OBJS} ${LDFLAGS} -o ${TARGET}

.SUFFIXES: .c .o

.c.o:
	@echo ".c.o"
	${CC} ${CFLAGS} -c $< -o $@

clean:
	@echo "clean"
	rm -f ${OBJS} ${TARGET} *.core

run: ${TARGET}
	@echo "run"
	./${TARGET}

install: ${TARGET}
	@echo "install"
	rm -f /usr/local/bin/${TARGET}
	cp ${TARGET} /usr/local/bin/${TARGET}

commit:
	@echo "commit"
	git add .
	git commit -m "AUTO COMMIT: `date +'%Y-%m-%d %H:%M:%S'`"
	git push origin main

.PHONY: all clean run install commit

