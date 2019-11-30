#if 1
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>

int my_init(void)
{
	struct task_struct *g,*t;

	do_each_thread(g, t)
	{
		if( g==t )
			printk("%6d  %s\n", g->pid, g->comm );
		else
			printk("\t\t%6d  %s\n", t->pid, t->comm );
	} while_each_thread(g, t) ;

	return 0;
}

void my_exit(void)
{
}

MODULE_LICENSE("GPL");
module_init( my_init );
module_exit( my_exit );
#endif
