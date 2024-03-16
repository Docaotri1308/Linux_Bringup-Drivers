#include <linux/module.h>   /* This module defines functions such as module_init/module_exit */
#include <linux/io.h>       /* This module defines functions such as ioremap/iounmap */
#include "gpio.h"           /* Gpio modules */

#define DRIVER_AUTHOR "cauchy caotricg1308@gmail.com"
#define DRIVER_DESC   "Turn on and turn off led"

uint32_t __iomem *gpio1_base_addr;

/* Constructor */
static int __init gpio_init(void)
{
    gpio1_base_addr = ioremap(GPIO1_ADDR_BASE, GPIO1_ADDR_SIZE);
    if(!gpio1_base_addr)
        return -ENOMEM;
    
    /* Set GPIO1_19 as output mode and turn on */
    *(gpio1_base_addr + GPIO_OE_OFFSET / 4) &= ~GPIO1_19;
    *(gpio1_base_addr + GPIO_SETDATAOUT_OFFSET / 4) |= GPIO1_19;

    pr_info("Hello! Initizliaze successfully!\n");
    return 0;
}

/* Destructor */
static void __exit gpio_exit(void)
{
    *(gpio1_base_addr + GPIO_CLEARDATAOUT_OFFSET / 4) |= GPIO1_19;
    iounmap(gpio1_base_addr);

    pr_info("Good bye my friend !!!\n");
}

module_init(gpio_init);
module_exit(gpio_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC); 
MODULE_VERSION("1.0"); 