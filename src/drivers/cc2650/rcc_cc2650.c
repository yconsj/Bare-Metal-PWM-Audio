#include "rcc_cc2650.h"

void rcc_peripheral_enable(GPIO_PORT port) {
    //CC2650_gpio_t *gpio = hal_to_cc2650_port(port);  
    return;
}

volatile uint32_t systick_counter = 0;



void systick_init(void) {
    CC2650_SYSTICK->CTRL = 0;
    CC2650_SYSTICK->LOAD = (CC2650_CLOCK_FREQ_MHZ * 1000) - 1;
    CC2650_SYSTICK->VAL = 0;
    CC2650_SYSTICK->CTRL |= CC2650_SYSTICK_CTRL_ENABLE | CC2650_SYSTICK_CTRL_INTERRUPT_ENABLE | CC2650_SYSTICK_CTRL_CLKSOURCE;
}

void delay_ms(uint32_t ms) {
    systick_counter = ms;
    while (systick_counter > 0);
}

void SysTick_Handler(void) {
    if (systick_counter > 0) {
        systick_counter--;
    }
}
