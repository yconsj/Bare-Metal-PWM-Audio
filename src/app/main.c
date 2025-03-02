#include <stdint.h>
#include "../hal/gpio_driver.h"



int main(void) {

    gpio_params_t gpio_params = {
        .pin = PIN_5,
        .mode = GPIO_OUTPUT,
        .cnf = GPIO_ANALOG
    };
    gpio_init(GPIOB, &gpio_params);
    
    
    // blink
    while (1) {
        gpio_toggle(GPIOB, PIN_13); // PB13_LED
        for (volatile int i = 0; i < 1000000; i++);
    }
}
