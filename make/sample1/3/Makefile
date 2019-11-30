.PHONY: all clean

TARGET = test main
SUBDIRS = main_src io

all :
	for i in $(SUBDIRS); do cd $$i; make;cd ..; done 
	cp ./main_src/main ./ 
	cp ./io/test ./ 


clean:
	for i in $(SUBDIRS);do cd $$i; make clean; cd ..;done
	rm $(TARGET)
