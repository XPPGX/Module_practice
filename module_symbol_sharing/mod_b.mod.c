#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x72f367e8, "add" },
	{ 0x122c3a7e, "_printk" },
	{ 0x47e64c59, "module_layout" },
};

MODULE_INFO(depends, "mod_a");


MODULE_INFO(srcversion, "BEED09938E7B06E24659203");
