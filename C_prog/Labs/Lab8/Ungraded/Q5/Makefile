CC = gcc
CFLAGS = -Wall
DEBUGFLAGS = -Wall -g

TARGET = Q5
DEBUG_TARGET = Q5_debug

SRC = main.c student.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

debug: $(OBJ)
	$(CC) $(DEBUGFLAGS) $^ -o $(DEBUG_TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET) $(DEBUG_TARGET)