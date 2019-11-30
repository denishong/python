hellow : hellow.o main.o
	gcc -o hellow  hellow.o main.o

hello.o : hellow.c 
	gcc -c hellow.c

main.o : main.c hellow.h
	gcc -c main.c
