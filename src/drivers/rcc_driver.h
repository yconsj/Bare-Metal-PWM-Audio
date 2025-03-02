#ifndef RCC_DRIVER_H
#define RCC_DRIVER_H

#include "stm32f103rb.h"

void rcc_peripheral_enable(gpio_t *gpio);

void systick_init(void);
void SysTick_Handler(void);
void delay_ms(uint32_t ms);
#endif
