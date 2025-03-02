#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include <stdint.h>
#include "pin.h"
typedef enum {
    GPIO_INPUT,
    GPIO_OUTPUT,
    GPIO_ANALOG,
    GPIO_ALTERNATE_FUNCTION
} GPIO_MODE;
typedef struct {
    PIN pin;
    GPIO_MODE mode;
    GPIO_CNF cnf;
} gpio_params_t;

// Function prototypes (must be implemented by the MCU-specific layer)
void gpio_init(GPIO_PORT port, gpio_params_t *params);
void gpio_write(GPIO_PORT port, uint16_t pin, uint8_t value);
uint8_t gpio_read(GPIO_PORT port, uint16_t pin);
void gpio_toggle(GPIO_PORT port, uint16_t pin);

    #ifdef stm32f103rb
        #include "..\drivers\stm32f103rb\gpio_stm32f103rb.h"
    #else 
    #ifdef cc2650 
        #include "..\drivers\ticc2650\gpio_cc2650.h"
    #else
    //...
    #endif
    #endif

#endif
