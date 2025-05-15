#include "gpio_cc2650.h"
#include "ioc_cc2650.h"



void gpio_set_high(uint8_t pin) {
    CC2650_GPIO->DOUTSET31_0 = (1 << pin);  // Set pin HIGH
}

void gpio_set_low(uint8_t pin) {
    CC2650_GPIO->DOUTCLR31_0 = (1 << pin);  // Set pin LOW
}

void gpio_toggle(uint8_t pin) {
    CC2650_GPIO->DOUTTGL31_0 = (1 << pin);  // Toggle pin
}

int gpio_read(uint8_t pin) {
    int res = (CC2650_GPIO->DIN31_0 & (1 << pin)) ? 1 : 0; 
    return res;  // Read input state
}

// GPIO initialization function (hardware-specific)
void gpio_init(gpio_params_t *gpio_params) {
    ASSERT(1==2);
    int pin = gpio_params->pin;
    
    
    // Enable the clock for the GPIO peripheral
    //rcc_peripheral_enable(pin);

    if (gpio_params->mode == GPIO_OUTPUT){
        IOCPinTypeGpioOutput(pin);
    }
    else {
        IOCPinTypeGpioInput(pin);
    }
}
const int dioNumberLegal(const uint32_t dioNumber) {
    return (dioNumber <  NUM_IO_MAX);
}

void GPIO_setOutputEnableDio( const uint32_t dioNumber, uint32_t outputEnableValue )
{
    // Check the arguments.
    ASSERT(dioNumberLegal(dioNumber));
    ASSERT(( outputEnableValue == GPIO_OUTPUT_DISABLE ) ||
           ( outputEnableValue == GPIO_OUTPUT_ENABLE  ));

    // Update the output enable bit for the specified DIO.
    HWREGBITW( GPIO_BASE + GPIO_O_DOE31_0, dioNumber ) = outputEnableValue;
}
