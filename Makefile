# Target
TARGET=					warm

# Compilers
CC=						clang

# Directories
SRCDIR=					./src
INCDIR=					./inc
BINDIR=					./bin
OBJDIR=					./obj
INCDIRS=				-I${INCDIR} -I.
LIBDIRS=

# Flags
DEBUG=					-g3 -O0 -DTESTING
C_WARN=					-Wall -Wextra -Werror -Wpedantic
C_STD=					-ansi
CFLAGS=					${INCDIRS} ${DEBUG} ${C_WARN} ${C_STD}
LDFLAGS=				${LIBDIRS} ${DEBUG} ${LDLIBS}

# Source files
SRCS=					${SRCDIR}/main.c ${SRCDIR}/dot.c	
OBJS=					${OBJDIR}/main.o ${OBJDIR}/dot.o	

# Default target
all: ${BINDIR}/${TARGET}
	@echo "Build complete."

${BINDIR}/${TARGET}: ${OBJS} | ${BINDIR}
	@echo "Linking target..."
	${CC} ${OBJS} ${LDFLAGS} -o $@

${OBJDIR}/%.o: ${SRCDIR}/%.c | ${OBJDIR}
	@echo "Compiling $<"
	${CC} ${CFLAGS} -c $< -o $@

${OBJDIR}:
	mkdir -p ${OBJDIR}

${BINDIR}:
	mkdir -p ${BINDIR}

clean:
	@echo "Cleaning..."
	rm -f ${OBJDIR}/*.o ${BINDIR}/${TARGET} *.core

run: ${BINDIR}/${TARGET}
	@echo "Running..."
	./${BINDIR}/${TARGET}

install: ${BINDIR}/${TARGET}
	@echo "Installing..."
	rm -f /usr/local/bin/${TARGET}
	cp ${BINDIR}/${TARGET} /usr/local/bin/${TARGET}

commit:
	@echo "Committing..."
	git add .
	git commit -m "AUTO COMMIT: `date +'%Y-%m-%d %H:%M:%S'`"
	git push origin main

debug:
	echo ${SRCS}
	echo ${OBJS}

.PHONY: all clean run install commit debug

