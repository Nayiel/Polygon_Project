# Compiler and flags
CC = gcc
CFLAGS = -std=c99 -Iinclude 
LDFLAGS = -lm -ldl -pthread
# LDFLAGS = -lraylib -lm -ldl -pthread
#CFLAGS = -Wall -Wextra -std=c99

# Project files
TARGET = test-winding
SRC = main.c polygon.c
OBJ = $(SRC:.c=.o)

# Default target
all: $(TARGET)


# Build the executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# Build the object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJ) 

# Phony targets to prevent filename clashes
.PHONY: all clean
