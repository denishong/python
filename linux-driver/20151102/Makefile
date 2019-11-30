obj-m = my_timer.o
KDIR = /usr/src/linux-headers-3.16.0-41
PWD  = $(shell pwd) 

default : 
	$(MAKE)  -C  $(KDIR)  SUBDIRS=$(PWD)  modules

clean : 
	$(MAKE)  -C  $(KDIR)  SUBDIRS=$(PWD)  clean
