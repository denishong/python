CC =gcc
CFLAG=-W -Wall
TARGET=hsi_print
OBJECTS=main.o print1.o print2.o print3.o

all : $(TARGET)

$(TARGET):$(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm *.o $(TARGET)
