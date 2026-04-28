CC = gcc
CFLAGS = -Wall
TARGET = sub
OBJS = sub.o main.o

all: sub

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c sub.h
	$(CC) $(CFLAGS) -c main.c

sub.o: sub.c sub.h
	$(CC) $(CFLAGS) -c sub.c

run: $(TARGET)
	./$(TARGET)

clean: 
	rm -f *.o $(TARGET)

.PHONY: all run clean