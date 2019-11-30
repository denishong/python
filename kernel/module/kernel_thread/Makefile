obj-m += kernel_thread.o 

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules 

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

install:
#	sudo rmmod hello
	sudo mkdir -p /lib/modules/$(KVERSION)/kernel/drivers/kernel_thread
	sudo cp hello.ko /lib/modules/$(KVERSION)/kernel/drivers/kernel_thread
	sudo depmod -a
	sudo modprobe kernel_thread 
