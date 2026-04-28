CC = gcc
CFLAGS = -Wall
TARGET = buildarray
OBJS = buildarray.o main.o

all: buildarray

$(TARGET): $(OBJS) 
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o : main.c buildarray.h
	$(CC) $(CFLAGS) -c main.c

buildArray.o : buildarray.c buildarray.h
	$(CC) $(CFLAGS) -c buildarray.c

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f *.o $(TARGET)

.PHONY: all run clean