# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g 

# the build target executable:
TARGET = matrix

all: matrix_anim matrix_text

matrix_anim: matrix_anim.c
	$(CC) $(CFLAGS) -o matrix_anim matrix_anim.c

matrix_text: matrix_text.c
	$(CC) $(CFLAGS) -o matrix_text matrix_text.c

clean:
	$(RM) $(TARGET)

