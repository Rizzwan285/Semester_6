CC = gcc
CFLAGS = -Wall
TARGET = Q4
SRC = main.c students.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

debug: $(OBJ)
	$(CC) $(DEBUGFLAGS) $^ -o $(DEBUG_TARGET)

clean:
	rm -f *.o $(TARGET)

help:
	@echo "Available commands:"
	@echo "make       - Build the program"
	@echo "make run   - Run the program"
	@echo "make clean - Delete generated files"
	@echo "make help  - Show available commands"