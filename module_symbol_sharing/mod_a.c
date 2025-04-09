#include <linux/init.h>
#include <linux/module.h>

int add(int a, int b)
{
    return a + b;
}

EXPORT_SYMBOL(add); //export the function "add" for the usage of other modules

static int __init mod_a_init(void)
{
    printk(KERN_INFO "mod_a loaded\n");
    return 0;
}

static void __exit mod_a_exit(void)
{
    printk(KERN_INFO "mod_a unloaded\n");
}

module_init(mod_a_init);
module_exit(mod_a_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Module A exporting symbol");