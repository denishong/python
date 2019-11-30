#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/gfp.h>

int my_init(void)
{
	printk("sizeof(struct page)=%lu\n", sizeof(struct page) );
	return 0;
}

void my_exit(void)
{
}

MODULE_LICENSE("GPL");
module_init( my_init );
module_exit( my_exit );
