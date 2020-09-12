.SUFFIX = .c .o
.PHONY: clean 
CC = gcc
CFLAGS = -W -Wall
TARGET = test_print

#List of directories to search for .c files
dirs := . sub1 sub1/sub11 sub2

#Extra directories to check for dependencies
VPATH = sub1 sub1/sub11 sub2

#make a list of *.c source files in directories
sources := $(foreach dir, $(dirs),$(wildcard $(dir)/*.c))

#list of needed objects
OBJS_T := $(patsubst %.c, %.o, $(sources))
#OBJS = main.o print1.o print2.o print3.o print4.o print21.o print111.o

#objects with full path names to their location in temp dir.
TempObjects = $(addprefix $(OBJS_T)/, $(notdir,$(OBJS_T)))

CFLAGS = -I include
include ./sub1/makefile
#vpath %.c sub1 sub1/sub11 sub2
vpath %.h include

#Compile
$(OBJS_T)\%.o:%.c
	$(CC) $(CFLAGS) $(OBJS_T) -c $@ 

#Link
$(TARGET) : $(TempObjects) 
	$(CC) $(CFLAGS) $(OBJS_T) -o $@ 

check_val :
	@echo 'Compiler: $(CC)'
	@echo 'directory : $(dirs)'
	@echo 'source files : $(sources)'
	@echo 'Object files : $(OBJS_T)'
	@echo 'TempObjects files : $(TempObjects)'
clean:
	rm -rf  $(OBJS) $(TARGET) 
