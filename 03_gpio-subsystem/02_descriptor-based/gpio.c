#include <linux/module.h>           /* Defines functions such as module_init/module_exit */
#include <linux/gpio.h>             /* Defines functions such as gpio_request/gpio_free */
#include <linux/platform_device.h>  /* For platform devices */
#include <linux/gpio/consumer.h>    /* For GPIO Descriptor */
#include <linux/of.h>               /* For DT */  

#define DRIVER_AUTHOR "cauchy caotricg1308@gmail.com"
#define DRIVER_DESC   "gpio subsystem"

#define LOW     0
#define HIGH    1

struct gpio_desc *gpio1_19;

static const struct of_device_id gpiod_dt_ids[] = {
    { .compatible = "gpio-descriptor-based", },
    { /* sentinel */ }
};

static int my_pdrv_probe(struct platform_device *pdev) {
    struct device *dev = &pdev->dev;
    gpio1_19 = gpiod_get(dev, "led51", GPIOD_OUT_LOW);
    gpiod_set_value(gpio1_19, HIGH);

    pr_info("%s - %d", __func__, __LINE__);
    return 0;
}

static int my_pdrv_remove(struct platform_device *pdev) {
    gpiod_set_value(gpio1_19, LOW);
    gpiod_put(gpio1_19);

    pr_info("%s - %d", __func__, __LINE__);
    return 0;
}

/* platform driver */
static struct platform_driver mypdrv = {
    .probe = my_pdrv_probe,
    .remove = my_pdrv_remove,
    .driver = {
        .name = "descriptor-based",
        .of_match_table = of_match_ptr(gpiod_dt_ids),
        .owner = THIS_MODULE,
    },
};
module_platform_driver(mypdrv);

MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
MODULE_VERSION("1.0");