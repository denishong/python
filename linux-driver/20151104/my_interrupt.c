#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/interrupt.h>

irqreturn_t my_irq_handler(int irq, void *id)
{
	printk("my_irq_handler(), irq=%d, id=%p\n", irq, id);
	return IRQ_HANDLED;
}

int my_init(void)
{
	int ret;
	unsigned long flags = 0x83UL;
	printk("my_init()\n");
    ret = request_irq( 379, my_irq_handler, flags, "MY_INT", (void*)0x1234UL);
	return 0;
}

void my_exit(void)
{
	printk("my_exit()\n");
	free_irq( 379, (void*)0x1234UL);
}

MODULE_LICENSE("GPL");
module_init( my_init );
module_exit( my_exit );

