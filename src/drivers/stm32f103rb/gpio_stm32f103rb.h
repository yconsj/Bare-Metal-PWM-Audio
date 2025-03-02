#ifndef GPIO_STM32F103RB_H
#define GPIO_STM32F103RB_H

#include <stdint.h>
#include <stddef.h>
#include "registers_stm32f103rb.h"
#include "../../hal/gpio_driver.h"
#include "../../hal/rcc_driver.h"
typedef struct {
    volatile uint32_t CRL;
    volatile uint32_t CRH;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t BRR;
    volatile uint32_t LCKR;
} STM32_gpio_t;

typedef enum {
    STM32_GPIO_INPUT = 0b00,
    STM32_GPIO_OUTPUT_10MHZ,
    STM32_GPIO_OUTPUT_2MHZ,
    STM32_GPIO_OUTPUT_50MHZ,
    STM32_GPIO_OUTPUT = STM32_GPIO_OUTPUT_2MHZ,
} STM32_GPIO_MODE;
typedef enum {
    STM32_GPIO_ANALOG = 0b00,
    STM32_GPIO_PULL = 0b10
} STM32_GPIO_CNF;


// Convert HAL mode to STM32 mode
STM32_GPIO_MODE hal_to_stm32_mode(GPIO_MODE mode);
STM32_GPIO_CNF hal_to_stm32_cnf(GPIO_CNF cnf);
STM32_gpio_t* hal_to_stm32_port(GPIO_PORT port);

/* GPIO Macros */
#define STM32_GPIO_CR_REGISTER(gpio, pin)     ((pin) > 7 ? &(gpio->CRH) : &(gpio->CRL))
#define STM32_GPIO_CNF_MASK(pin)              (0b11 << (((pin % 8) * 4) + 2))
#define STM32_GPIO_MODE_MASK(pin)             (0b11 << ((pin % 8) * 4))
#define STM32_GPIO_CNF_PINS(pin)              (((pin % 8) * 4) + 2)
#define STM32_GPIO_MODE_PINS(pin)             ((pin % 8) * 4)

#endif