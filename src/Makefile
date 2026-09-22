# src/Makefile - does the actual compiling and linking

CC = gcc
CFLAGS = -Wall -Wextra -I../include
SRC = main.c mystrfunctions.c myfilefunctions.c
OBJ = $(SRC:.c=.o)
TARGET = ../bin/client

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
