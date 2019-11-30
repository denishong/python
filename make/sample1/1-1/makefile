.SUFFIX = .c .o
OBJS = main.o write.o read.o
SRC = main.c write.c read.c
#VPATH = src include
#CPPFLAGS = -I include
vpath %.c src code
vpath %.h include

test : $(OBJS)
	gcc -o $@ $(OBJS)

main.o : main.c io.h
	gcc -c $< 
write.o : write.c io.h
	gcc -c $< 
read.o : read.c io.h
	gcc -c $< 


clean:
	rm $(OBJS) test 
