#include "gpio_stm32f103rb.h"



// Convert HAL mode to STM32 mode
STM32_GPIO_MODE hal_to_stm32_mode(GPIO_MODE mode) {
    switch (mode) {
        case GPIO_INPUT: return STM32_GPIO_INPUT;
        case GPIO_OUTPUT: return STM32_GPIO_OUTPUT;
        case GPIO_ANALOG: return STM32_GPIO_ANALOG;
        default: return STM32_GPIO_INPUT;  // Default to input
    }
}

// Convert HAL configuration (CNF) to STM32 configuration
STM32_GPIO_CNF hal_to_stm32_cnf(GPIO_CNF cnf) {
    switch (cnf) {
        case GPIO_CNF_ANALOG: return STM32_GPIO_ANALOG;
        case GPIO_CNF_PULL: return STM32_GPIO_PULL;
        default: return STM32_GPIO_ANALOG;
    }
}

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

    // Select the correct control register (CRL or CRH)
    volatile uint32_t *cr = STM32_GPIO_CR_REGISTER(gpio, gpio_params->pin);

    // Clear mode and configuration bits
    *cr &= ~STM32_GPIO_MODE_MASK(gpio_params->pin);  // Clear MODE
    *cr &= ~STM32_GPIO_CNF_MASK(gpio_params->pin);   // Clear CNF

    // Set mode and configuration
    *cr |= (hal_to_stm32_cnf(gpio_params->cnf) << STM32_GPIO_CNF_PINS(gpio_params->pin));
    *cr |= (hal_to_stm32_mode(gpio_params->mode) << STM32_GPIO_MODE_PINS(gpio_params->pin));
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