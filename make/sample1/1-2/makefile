.PHONY: all test clean
.SUFFIX = .c .o
#OBJS = $(subst .c,.o,$(SRC)) 
#SRC = *.c 
OBJS = main.o write.o read.o
SRC = main.c write.c read.c
#VPATH = src include
#CPPFLAGS = -I include
vpath %.c src code
vpath %.h inc
OUTPUT = output/model/product
player := app/player


OUTPUT := $(shell mkdir -p $(OUTPUT))
CC = gcc

#.c.o :
#	$(CC) -c $<

test : $(OBJS)
	$(CC) -o $@ $(OBJS)

help:
	@echo $(CC) $(TEMP)

clean:
	rm $(OBJS) test 
