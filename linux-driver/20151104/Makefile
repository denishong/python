
obj-m = my_thread_list.o
KDIR = /usr/src/tegra
PWD  = $(shell pwd) 

default : 
	$(MAKE)  -C  $(KDIR)  SUBDIRS=$(PWD)  modules

clean : 
	$(MAKE)  -C  $(KDIR)  SUBDIRS=$(PWD)  clean
