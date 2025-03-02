#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include <stdint.h>
#include "stm32f103rb.h"



typedef struct {
    PIN pin;
    GPIO_MODE mode;
    GPIO_SPEED speed;
    GPIO_OUTPUT_CONFIG output_config;
    GPIO_INPUT_CONFIG input_config;
} gpio_params_t;

void gpio_init(gpio_t *gpio, gpio_params_t* gpio_params);
void gpio_toggle(gpio_t *gpio, uint8_t pin);


#endif
