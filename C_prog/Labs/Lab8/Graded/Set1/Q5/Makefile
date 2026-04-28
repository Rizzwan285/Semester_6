CC = gcc
CFLAGS = -Wall
TARGET = string_ops
OBJS = main.o string_ops.o

all: string_ops

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c string_ops.h
	$(CC) $(CFLAGS) -c main.c

string_ops.o: string_ops.c string_ops.h
	$(CC) $(CFLAGS) -c string_ops.c

run: $(TARGET)
	./$(TARGET)

clean: 
	rm -f *.o $(TARGET)

.PHONY: all run clean