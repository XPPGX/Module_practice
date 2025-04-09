#include <linux/init.h>
#include <linux/module.h>

extern int add(int a, int b); //use the

static int __init mod_b_init(void)
{
    int result = add(3, 4);
    printk(KERN_INFO "mod_b[init]: result of add(3, 4) = %d\n", result);
    return 0;
}

static void __exit mod_b_exit(void)
{
    printk(KERN_INFO "mod_b[exit]\n");
}

module_init(mod_b_init);
module_exit(mod_b_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Module B use the symbol exported by module A");