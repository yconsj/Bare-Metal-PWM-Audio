#include <stdint.h>
#include "../hal/gpio_driver.h"

volatile uint8_t test_buffer[1024];

int main(void) {
    systick_init();
    gpio_params_t gpio_params = {
        .pin = PIN_5,
        .mode = GPIO_OUTPUT,
        .output_config = GPIO_MODE_OUTPUT_PP
    };
    gpio_init(&gpio_params);
    int a = 2;
    int b = a + 2;
    int* p = &b;
    a = b;
    p = &a;
    a = *p+b;


    // blink
    while(1){
        gpio_toggle(PIN_6);
        delay_ms(1000);
    }

    
}
