#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/slab.h>

#define L1_CACHE_SHIFT		6
#define L1_CACHE_BYTES		(1 << L1_CACHE_SHIFT)
#define ARCH_MIN_TASKALIGN	L1_CACHE_BYTES

static struct kmem_cache *my_struct_cachep;
struct my_struct 
{
	int gpio;
	int irq;
	char name[20];
};

int my_init(void)
{
	char *cp;
	struct my_struct *p;
	my_struct_cachep =   kmem_cache_create(
			"my_struct", 
			sizeof(struct my_struct),
			ARCH_MIN_TASKALIGN, 
			SLAB_PANIC | SLAB_NOTRACK, 
			NULL);
	p = kmem_cache_alloc( my_struct_cachep, GFP_KERNEL );
	p->gpio=123;
	p->irq= 372;
	strcpy(p->name, "my_dev_info");
	printk("%d, %d, %s\n", p->gpio, p->irq, p->name );
	kmem_cache_free( my_struct_cachep, p  );
	kmem_cache_destroy( my_struct_cachep );
	cp = kmalloc(32, GFP_KERNEL);
	cp[0]  = 'a';
	cp[31] = 'z';
	printk("%c - %c\n", cp[0], cp[31] );
	kfree( cp );
	return 0;
}

void my_exit(void)
{
}

MODULE_LICENSE("GPL");
module_init( my_init );
module_exit( my_exit );
