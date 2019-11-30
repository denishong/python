#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x9452278, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xa916b694, __VMLINUX_SYMBOL_STR(strnlen) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x4302d0eb, __VMLINUX_SYMBOL_STR(free_pages) },
	{ 0xcd193052, __VMLINUX_SYMBOL_STR(init_task) },
	{ 0x93fca811, __VMLINUX_SYMBOL_STR(__get_free_pages) },
	{ 0x4829a47e, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0xa13e1199, __VMLINUX_SYMBOL_STR(mmput) },
	{ 0x7bd32066, __VMLINUX_SYMBOL_STR(up_read) },
	{ 0x6a70027b, __VMLINUX_SYMBOL_STR(put_page) },
	{ 0xf8e398fc, __VMLINUX_SYMBOL_STR(memstart_addr) },
	{ 0x6bcb6e07, __VMLINUX_SYMBOL_STR(__might_sleep) },
	{ 0xee791380, __VMLINUX_SYMBOL_STR(__get_user_pages) },
	{ 0xe43cdde0, __VMLINUX_SYMBOL_STR(down_read) },
	{ 0xa1b02782, __VMLINUX_SYMBOL_STR(get_task_mm) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

