CC = gcc
OBJS = test.o 
SRC = test.c 
.PHONY: all clean

TARGET = test


$(TARGET) : $(OBJS)
	$(CC) -o $@  $(OBJS) $(CFLAGS)

test.o : test.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm $(OBJS) $(TARGET)
