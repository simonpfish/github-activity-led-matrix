# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g 

# the build target executable:
TARGET = matrix

all: word_frames; matrix;

word_frames: word_frames.c
	$(CC) $(CFLAGS) -o word_frames word_frames.c

matrix: matrix.c
	$(CC) $(CFLAGS) -o matrix matrix.c

clean:
	$(RM) $(TARGET)

