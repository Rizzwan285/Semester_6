CC = gcc
CFLAGS = -Wall
TARGET = ops
OBJS = ops.o main.o

all: ops

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

ops.o: ops.c ops.h
	$(CC) $(CFLAGS) -c ops.c

main.o: main.c ops.h
	$(CC) $(CFLAGS) -c main.c

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f *.o $(TARGET)

.PHONY: run clean all