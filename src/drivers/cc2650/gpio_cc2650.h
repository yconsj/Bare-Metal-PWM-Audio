#ifndef GPIO_CC2650F103RB_H
#define GPIO_CC2650F103RB_H

#define GPIO_OUTPUT_DISABLE     0x00000000  // DIO output is disabled
#define GPIO_OUTPUT_ENABLE      0x00000001  // DIO output is enabled

#include <stdint.h>
#include <stddef.h>
#include "registers_cc2650.h"
#include "hw_types_cc2650.h"
#include "hw_gpio_cc2650.h"
#include "../../hal/gpio_driver.h"
#include "../../hal/rcc_driver.h"
#include "debug_cc2650.h"
#include "rcc_cc2650.h"





typedef struct {
    volatile uint32_t RESERVED_0[32];  // Skip offsets 0x00 - 0x7C (per-DIO outputs)
    volatile uint32_t DOUT31_0;        // Offset 0x80 - Data output register
    volatile uint32_t DOUTSET31_0;     // Offset 0x90 - Set output
    volatile uint32_t DOUTCLR31_0;     // Offset 0xA0 - Clear output
    volatile uint32_t DOUTTGL31_0;     // Offset 0xB0 - Toggle output
    volatile uint32_t DIN31_0;         // Offset 0xC0 - Read input
    volatile uint32_t DOE31_0;         // Offset 0xD0 - Output enable (1 = output, 0 = input)
    volatile uint32_t EVFLAGS31_0;     // Offset 0xE0 - Event flags (interrupts)
} CC2650_gpio_t;


#define CC2650_PORTID_GPIO        (0x0)
#define CC2650_GPIO               ((CC2650_gpio_t*) CC2650_GPIO_BASE)

void gpio_init(gpio_params_t *gpio_params);

void gpio_set_high(uint8_t pin);

void gpio_set_low(uint8_t pin);

void gpio_toggle(uint8_t pin);

int gpio_read(uint8_t pin);


typedef enum {
    CC2650_GPIO_10MHZ = 1
} CC2650_GPIO_SPEED;

const int dioNumberLegal(const uint32_t dioNumber) ;
void GPIO_setOutputEnableDio( const uint32_t dioNumber, uint32_t outputEnableValue );


#endif