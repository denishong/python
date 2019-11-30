CC = gcc
OBJS = main.o write.o read.o
SRC = main.c write.c read.c 
.PHONY: all clean

TARGET = main


$(TARGET) : $(OBJS)
	$(CC) -o $@  $(OBJS) $(CFLAGS)

main.o : main.c
	$(CC) -c $< $(CFLAGS)
write.o : write.c
	$(CC) -c $< $(CFLAGS)
read.o : read.c
	$(CC) -c $< $(CFLAGS)
clean:
	rm $(OBJS) $(TARGET)
