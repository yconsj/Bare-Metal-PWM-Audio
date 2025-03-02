#include <stdint.h>
#include "rcc_driver.h"
void rcc_peripheral_enable(gpio_t *gpio){
    if (gpio == GPIOA) {
        RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
    }
    if (gpio == GPIOB) {
        RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
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
    SYSTICK->CTRL = 0;
    SYSTICK->LOAD = (CLOCK_FREQ_MHZ * 1000) - 1;
    SYSTICK->VAL = 0;
    SYSTICK->CTRL |= SYSTICK_CTRL_ENABLE | SYSTICK_CTRL_INTERRUPT_ENABLE | SYSTICK_CTRL_CLKSOURCE;
}

void delay_ms(uint32_t ms) {
    systick_counter = ms;
    while (systick_counter > 0);
}
