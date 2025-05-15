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


volatile uint32_t systick_counter = 0;

void SysTick_Handler(void) {
    if (systick_counter > 0) {
        systick_counter--;
    }
}

void systick_init(void) {
    STM32_SYSTICK->CTRL = 0;
    STM32_SYSTICK->LOAD = (STM32_CLOCK_FREQ_MHZ * 1000) - 1;
    STM32_SYSTICK->VAL = 0;
    STM32_SYSTICK->CTRL |= STM32_SYSTICK_CTRL_ENABLE | STM32_SYSTICK_CTRL_INTERRUPT_ENABLE | STM32_SYSTICK_CTRL_CLKSOURCE;
}

void delay_ms(uint32_t ms) {
    systick_counter = ms;
    while (systick_counter > 0);
}