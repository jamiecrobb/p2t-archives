# Configuration
CC=clang
CFLAGS=-Wall -g
EXE=plot
OBJ=plot.o
LDFLAGS=-lm -L./extras/ -lturtle-intel-linux

# Default target: link the object code into the executable
${EXE}: ${OBJ}
			${CC} -o $@ $^ ${LDFLAGS}

# Compile object code from source code
%.o: %.c
			${CC} ${CFLAGS} -c $<

# Remove build objects
.PHONY: clean
clean:
	rm *.o ${EXE}

# Build the program and run it with CLI of 5
.PHONY: test
test:
	make && ./plot 5