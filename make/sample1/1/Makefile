.PHONY: clean
.SUFFIX = .c .o
OBJS = main.o write.o read.o
SRC = main.c write.c read.c
EXEC=$(SRC:.c=_deb.obj)

test : $(OBJS)
	gcc -o $@ $(OBJS)
#	echo $@ $< $?
	@echo $*
	@echo ${EXEC}


main.o : main.c io.h
	gcc -c $?
write.o : write.c io.h
	gcc -c $?
read.o : read.c io.h
	gcc -c $? 


clean:
	rm $(OBJS) test 
