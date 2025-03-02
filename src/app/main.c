#include <stdint.h>
#include "../hal/gpio_driver.h"



int main(void) {
    systick_init();
    gpio_params_t gpio_params = {
        .pin = PIN_5,
        .mode = GPIO_OUTPUT,
        .output_config = GPIO_MODE_OUTPUT_PP
    };
    gpio_init(GPIOA, &gpio_params);
    
    
    // blink
    while(1){
        gpio_toggle(GPIOA, PIN_5);
        delay_ms(1000);
    }

    
}
