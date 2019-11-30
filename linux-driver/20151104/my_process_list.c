#if 1
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>

int my_init(void)
{
	struct task_struct *p;

	for_each_process(p)
		printk("%6d  %s\n", p->pid, p->comm );

	return 0;
}

void my_exit(void)
{
}

MODULE_LICENSE("GPL");
module_init( my_init );
module_exit( my_exit );
#endif
#if 0
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>

int my_init(void)
{
	struct list_head *temp;
	struct task_struct *p;

	for( temp=init_task.tasks.next; temp!=&init_task.tasks; temp=temp->next )
	{
		p = list_entry( temp, struct task_struct, tasks );
		printk("%6d  %s\n", p->pid, p->comm );
	}


	return 0;
}

void my_exit(void)
{
}

MODULE_LICENSE("GPL");
module_init( my_init );
module_exit( my_exit );
#endif
#if 0
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>

int my_init(void)
{
	struct list_head *temp;
	struct task_struct *p;

	for( temp=current->tasks.next; temp!=&current->tasks; temp=temp->next )
	{
		p = list_entry( temp, struct task_struct, tasks );
		printk("%6d  %s\n", p->pid, p->comm );
	}
	p = list_entry( temp, struct task_struct, tasks );
	printk("%6d  %s\n", p->pid, p->comm );

	return 0;
}

void my_exit(void)
{
}

MODULE_LICENSE("GPL");
module_init( my_init );
module_exit( my_exit );
#endif
