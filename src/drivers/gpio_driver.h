#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include <stdint.h>
#include "stm32f103rb.h"



typedef struct {
    PIN pin;
    MODE mode;
    CNF cnf;
} gpio_params_t;

void gpio_init(gpio_t *gpio, gpio_params_t* gpio_params);
void gpio_toggle(gpio_t *gpio, uint8_t pin);


#endif
