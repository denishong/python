.SUFFIX = .c .o
.PHONY: clean 
CC = gcc
CFLAGS = -W -Wall
TARGET = test_print
OBJS = main.o print1.o print2.o print3.o print4.o  print11.o print21.o print111.o
CFLAGS = -I include
vpath %.c sub1 sub1/sub11 sub2
vpath %.h include

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ 

clean:
	rm -rf  $(OBJS) $(TARGET) 
