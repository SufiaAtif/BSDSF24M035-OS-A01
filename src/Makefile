CC = gcc
AR = ar
CFLAGS = -Wall -Wextra -I../include
ARFLAGS = rcs

LIB_SRC = mystrfunctions.c myfilefunctions.c
LIB_OBJ = $(LIB_SRC:.c=.o)
LIBRARY = ../lib/libmyutils.a

MAIN_SRC = main.c
MAIN_OBJ = $(MAIN_SRC:.c=.o)

TARGET = ../bin/client_static

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(MAIN_OBJ) $(LIBRARY)
	$(CC) $(MAIN_OBJ) -L../lib -lmyutils -o $(TARGET)

$(LIBRARY): $(LIB_OBJ)
	$(AR) $(ARFLAGS) $(LIBRARY) $(LIB_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(LIB_OBJ) $(MAIN_OBJ) $(LIBRARY) $(TARGET)
