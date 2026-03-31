CC = gcc
CFLAGS = -Wall
TARGET = Q4
SRC = main.c xor.c
OBJ = $(SRC:.c=.o)

.PHONY: all run clean help

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f *.o $(TARGET)

help:
	@echo "Available commands:"
	@echo "make       - Build the program"
	@echo "make run   - Run the program"
	@echo "make clean - Delete generated files"
	@echo "make help  - Show available commands"