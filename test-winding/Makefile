# Compiler and flags
CC = gcc
CFLAGS = -Wall
LDFLAGS = -lm -ldl -pthread -lraylib

# Project files
TARGET = test-winding
SRC = main.c polygon.c
OBJ = $(SRC:.c=.o)

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(TARGET)

# Build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJ)

# Phony targets
.PHONY: all clean
