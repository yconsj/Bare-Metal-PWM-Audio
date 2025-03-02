#include <stdint.h>
#include "gpio_driver.h"
#include "rcc_driver.h"
void gpio_init(gpio_t *gpio, gpio_params_t *gpio_params)  {
    rcc_peripheral_enable(gpio);
    
    uint8_t cnf;
    uint8_t mode;
    if (gpio_params->mode == GPIO_OUTPUT){
        cnf = gpio_params->output_config;
        mode = gpio_params->speed;
    }
    else {
        cnf = gpio_params->input_config;
        mode = 0;
    }

    volatile uint32_t *cr = GPIO_CR_REGISTER(gpio, gpio_params->pin);

    *cr &= ~GPIO_CNF_MASK(gpio_params->pin);
    *cr &= ~GPIO_MODE_MASK(gpio_params->pin);
    *cr |= (cnf << GPIO_CNF_PINS(gpio_params->pin));
    *cr |= (mode << GPIO_MODE_PINS(gpio_params->pin));
}
void gpio_toggle(gpio_t *gpio, uint8_t pin){
    gpio->ODR ^= (1 << pin);
}