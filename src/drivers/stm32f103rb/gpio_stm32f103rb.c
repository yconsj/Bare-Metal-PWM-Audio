#include "gpio_stm32f103rb.h"

STM32_gpio_t* hal_to_stm32_port(GPIO_PORT port) {
    switch (port) {
        case GPIOA: return STM32_GPIOA;
        case GPIOB: return STM32_GPIOB;
        case GPIOC: return STM32_GPIOC;
        case GPIOD: return STM32_GPIOD;
        default: return NULL; // raise error, out of bounds port?
    }
}


// GPIO initialization function (hardware-specific)
void gpio_init(GPIO_PORT port, gpio_params_t *gpio_params) {
    STM32_gpio_t *gpio = hal_to_stm32_port(port);

    // Enable the clock for the GPIO peripheral
    rcc_peripheral_enable(port);

    uint8_t cnf;
    uint8_t mode;
    if (gpio_params->mode == GPIO_OUTPUT){
        cnf = gpio_params->output_config;
        mode = STM32_GPIO_2MHZ; //gpio_params->speed;
    }
    else {
        cnf = gpio_params->input_config;
        mode = 0;
    }

    // Select the correct control register (CRL or CRH)
    volatile uint32_t *cr = GPIO_CR_REGISTER(gpio, gpio_params->pin);

    *cr &= ~STM32_GPIO_CNF_MASK(gpio_params->pin);
    *cr &= ~STM32_GPIO_MODE_MASK(gpio_params->pin);
    *cr |= (cnf << STM32_GPIO_CNF_PINS(gpio_params->pin));
    *cr |= (mode << STM32_GPIO_MODE_PINS(gpio_params->pin));
}

// GPIO toggle function
void gpio_toggle(GPIO_PORT port, uint16_t pin) {
    STM32_gpio_t *gpio = hal_to_stm32_port(port);
    gpio->ODR ^= (1 << pin);
}

// GPIO write function
void gpio_write(GPIO_PORT port, uint16_t pin, uint8_t value) {
    STM32_gpio_t *gpio = hal_to_stm32_port(port);   
    if (value)
        gpio->BSRR = (1 << pin);  // Set pin
    else
        gpio->BRR = (1 << pin);   // Reset pin
}

// GPIO read function
uint8_t gpio_read(GPIO_PORT port, uint16_t pin) {
    STM32_gpio_t *gpio = hal_to_stm32_port(port);   
    return (gpio->IDR & (1 << pin)) ? 1 : 0;
}