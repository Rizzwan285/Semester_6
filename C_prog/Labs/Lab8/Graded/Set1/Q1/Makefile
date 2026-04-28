CC = gcc
CFLAGS = -Wall
TARGET = prime_array

OBJS = main.o prime.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c prime.h
	$(CC) $(CFLAGS) -c main.c

prime.o: prime.c prime.h
	$(CC) $(CFLAGS) -c prime.c

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: run clean