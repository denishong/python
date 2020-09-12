#!/usr/bin/ld
.SUFFIX = .c .o
.PHONY: clean 
CC = gcc
CFLAGS := -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs
TARGET = test_print
OBJS = main.o print1.o print2.o print3.o print4.o  print11.o print21.o print111.o
CFLAGS = -I include
vpath %.c main sub1 sub1/sub11 sub2
vpath %.h include

SOURCES = $(wildcard main/*.c sub1/*.c sub1/sub11/*.c sub2/*.c)
OBJS = $(patsubst %.c, out/%.o, $(notdir $(SOURCES)))

KERNEL_OUT = out 
#all : $(TARGET)

all: build $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(OBJS)

$(OBJS) : $(SOURCES)
	$(CC) $(CFLAGS) -c $< -o $@ 

build :
	@mkdir -p out

clean:
	rm -rf  $(KERNEL_OUT) 

print_test:
	@echo $(SOURCES)
	@echo $(OBJS)
	@echo $(KERNEL_OUT)
