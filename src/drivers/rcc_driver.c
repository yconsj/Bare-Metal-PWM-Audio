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
