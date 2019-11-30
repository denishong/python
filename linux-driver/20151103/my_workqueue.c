#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/interrupt.h> // top half
#include <linux/workqueue.h> // bottom half
static struct work_struct my_work;
irqreturn_t my_irq_handler(int irq, void *id)
{
	printk("my_irq_handler(), irq=%d, id=%p\n", irq, id);
	schedule_work(&my_work); // work를 workqueue에 등록 
	return IRQ_HANDLED;
}
void my_work_handler(struct work_struct *work)
{
	printk("my_work_handler(), work=%p\n", work);
}
int my_init(void)
{
	int ret;
	unsigned long flags = 0x83UL;
	printk("my_init()\n");
    ret = request_irq( 379, my_irq_handler, flags, "MY_INT", (void*)0x1234UL);
	INIT_WORK( &my_work, my_work_handler);  // 핸들러 등록
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

