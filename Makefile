CC = gcc
#CFLAGS = -Wall -Wextra -std=c11 -O2 -g -mavx2
CFLAGS = -O2 -mavx2 -std=gnu17
INCLUDES = -Isrc
LDFLAGS = -lm -lX11 -lpng
LDFLAGSLIB = -lm

SRC_DIR = src
LIB_DIR = libs
BUILD_DIR = build
BIN_DIR = bin

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

LIB_FILES = $(wildcard $(LIB_DIR)/*.c)
SO_FILES = $(patsubst $(LIB_DIR)/%.c,$(BIN_DIR)/%.so,$(LIB_FILES))

TARGET = $(BUILD_DIR)/Main

all:
	$(CC) $(CFLAGS) $(INCLUDES) ./$(SRC_DIR)/Main.c -o ./$(TARGET) $(LDFLAGS) 

exe:
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR)/*

cleanlib:
	rm -rf $(BIN_DIR)/*

lib: $(SO_FILES)

$(BIN_DIR)/%.so: $(LIB_DIR)/%.c
	$(CC) $(CFLAGS) -fPIC -o $@ $< -shared $(LDFLAGSLIB)

dg: clean
	$(CC) $(CFLAGS) -g $(INCLUDES) ./$(SRC_DIR)/Main.c -o ./$(TARGET) $(LDFLAGS)
	gdb ./$(TARGET)

do: clean all exe