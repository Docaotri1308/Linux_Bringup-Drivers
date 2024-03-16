#ifndef __LED_MODULE_H__
#define __LED_MODULE_H__

#define GPIO1_ADDR_BASE     0x4804C000
#define GPIO1_ADDR_END      0x4804CFFF
#define GPIO1_ADDR_SIZE     (GPIO1_ADDR_END - GPIO1_ADDR_BASE)

#define GPIO_OE_OFFSET			    0x134
#define GPIO_CLEARDATAOUT_OFFSET	0x190
#define GPIO_SETDATAOUT_OFFSET		0x194

#define GPIO1_19                    (1 << 19)       /* P9_16 */

#endif  /* __LED_MODULE_H__ */