# Configuration
CC=clang
CFLAGS=-Wall -g
EXE=fractal
OBJ=fractal.o printppm.o

# Default target: link the object code into the executable
${EXE}: ${OBJ}
			${CC} -o $@ $^

# Compile object code from source code
%.o: %.c
			${CC} ${CFLAGS} -c $<

# Remove build objects
.PHONY: clean
clean:
	rm *.o ${EXE}
