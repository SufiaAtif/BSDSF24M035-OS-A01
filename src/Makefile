CC = gcc
AR = ar

CFLAGS = -Wall -Wextra -I../include
ARFLAGS = rcs

LIB_SRC = mystrfunctions.c myfilefunctions.c
LIB_OBJ = $(LIB_SRC:.c=.o)

LIBRARY_STATIC = ../lib/libmyutils.a
LIBRARY_DYNAMIC = ../lib/libmyutils.so

MAIN_SRC = main.c
MAIN_OBJ = $(MAIN_SRC:.c=.o)

TARGET_STATIC = ../bin/client_static
TARGET_DYNAMIC = ../bin/client_dynamic

INSTALL_DIR = /usr/local/bin
MAN_DIR = /usr/local/share/man/man3

.PHONY: all clean install

all: $(TARGET_STATIC) $(TARGET_DYNAMIC)

$(TARGET_STATIC): $(MAIN_OBJ) $(LIBRARY_STATIC)
	$(CC) $(MAIN_OBJ) -L../lib -lmyutils -o $(TARGET_STATIC)

$(LIBRARY_STATIC): $(LIB_OBJ)
	$(AR) $(ARFLAGS) $(LIBRARY_STATIC) $(LIB_OBJ)

$(TARGET_DYNAMIC): $(MAIN_OBJ) $(LIBRARY_DYNAMIC)
	$(CC) $(MAIN_OBJ) -L../lib -lmyutils -o $(TARGET_DYNAMIC)

$(LIBRARY_DYNAMIC): $(LIB_OBJ)
	$(CC) -shared -fPIC -o $(LIBRARY_DYNAMIC) $(LIB_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(LIB_OBJ) $(MAIN_OBJ) $(LIBRARY_STATIC) $(LIBRARY_DYNAMIC) $(TARGET_STATIC) $(TARGET_DYNAMIC)

install: $(TARGET_STATIC)
	mkdir -p $(INSTALL_DIR)
	mkdir -p $(MAN_DIR)
	cp $(TARGET_STATIC) $(INSTALL_DIR)/client
	cp ../man/man3/*.1 $(MAN_DIR)/
