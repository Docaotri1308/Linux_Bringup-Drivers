#include <linux/module.h>   /* Defines functions such as module_init/module_exit */
#include <linux/gpio.h>     /* Defines functions such as gpio_request/gpio_free */     

#define GPIO1_19            51

#define LOW                 0
#define HIGH                1

#define DRIVER_AUTHOR "cauchy caotricg1308@gmail.com"
#define DRIVER_DESC   "gpio subsystem"

/* Constructor */
static int __init gpio_init(void) {
    gpio_request(GPIO1_19, "GPIO1_19");
    gpio_direction_output(GPIO1_19, LOW);
    gpio_set_value(GPIO1_19, HIGH);

    pr_info("Hello! gpio status: %s!\n", gpio_get_value(GPIO1_19) ? "High" : "Low");
    return 0;
}

/* Destructor */
static void __exit gpio_exit(void) {
    gpio_set_value(GPIO1_19, LOW);
    gpio_free(GPIO1_19);
    pr_info("Good bye my friend !!!\n");
}

module_init(gpio_init);
module_exit(gpio_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC); 
MODULE_VERSION("1.0"); 