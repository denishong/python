#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>

int my_init(void)
{
	struct task_struct *p = current;
	printk("pid=%d, comm=%s\n", p->pid, p->comm );
	return 0;
}

void my_exit(void)
{
}

MODULE_LICENSE("GPL");
module_init( my_init );
module_exit( my_exit );

