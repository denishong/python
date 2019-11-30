.PHONY: clean hsi_print
CC =gcc
CFLAG=-W -Wall
TARGET=hsi_print
OBJS=main.o print1.o print2.o print3.o

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	rm $(OBJS) $(TARGET)
