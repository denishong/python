#include <linux/module.h>


static int __init hello_world_init(void)

{

	printk("hello world~\n");

	return 0;

}


static void __exit hello_world_fini(void)

{

	printk("good bye~\n");

}


module_init(hello_world_init);

module_exit(hello_world_fini);


MODULE_LICENSE("GPL");

MODULE_AUTHOR("denis hong <0330sisy@naver.com>");

MODULE_DESCRIPTION("Hello world for Linux Kernel module.");
