#include "rcc_stm32f103rb.h"

void rcc_peripheral_enable(GPIO_PORT port) {
    STM32_gpio_t *gpio = hal_to_stm32_port(port);  
    if (gpio == STM32_GPIOA) {
        STM32_RCC->APB2ENR |= STM32_RCC_APB2ENR_IOPAEN;
    }
    if (gpio == STM32_GPIOB) {
        STM32_RCC->APB2ENR |= STM32_RCC_APB2ENR_IOPBEN;
    }
    else return;

}