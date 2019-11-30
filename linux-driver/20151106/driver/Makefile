
obj-m = my_minor_driver.o
KDIR = /usr/src/tegra
PWD  = $(shell pwd) 

default : 
	$(MAKE)  -C  $(KDIR)  SUBDIRS=$(PWD)  modules

clean : 
	$(MAKE)  -C  $(KDIR)  SUBDIRS=$(PWD)  clean
