#include <stdint.h>
#include "../drivers/gpio_driver.h"
#include "../drivers/rcc_driver.h"
#include "../common/debug.h"
#include "../drivers/uart_driver.h"
int main(void) {
    systick_init();
    gpio_params_t gpio_params = {
        .pin = PIN_5,
        .mode = GPIO_OUTPUT,
        .output_config = GPIO_GP_OUTPUT_PP,
        .speed = GPIO_OUTPUT_SPEED_2MHZ
    };
    gpio_init(GPIOA, &gpio_params);
    uart_init();

    // blink
    while(1){
        gpio_toggle(GPIOA, PIN_5);
        delay_ms(1000);
        uart_putchar('t');
        uart_putchar('\n');
    }


}
