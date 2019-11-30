.PHONY: all clean

TARGET = test main
SUBTARGET = ./main_src/main ./io/test

all : $(TARGET)

$(TARGET) : $(SUBTARGET)
	cp ./main_src/main ./
	cp ./io/test ./

$(SUBTARGET) :
	for i in $(SUBDIRS); do \
		cd $$i;\
		make; \
		cd ..; \
		done 


clean:
	for i in $(SUBDIRS);do cd $$i; make clean; cd ..;done
	rm $(TARGET)
