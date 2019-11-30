obj-m += kthread.o 

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules 

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

install:
#	sudo rmmod hello
	sudo mkdir -p /lib/modules/$(KVERSION)/kernel/drivers/kthread
	sudo cp hello.ko /lib/modules/$(KVERSION)/kernel/drivers/kthread
	sudo depmod -a
	sudo modprobe kthread 
