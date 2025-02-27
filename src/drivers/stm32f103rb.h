#include <stdint.h>
#ifndef STM32F103RB_H
#define STM32F103RB_H

#define PERIPH_BASE         (0x40000000UL)
#define APB1_PERIPH_BASE    (PERIPH_BASE)
#define APB2_PERIPH_BASE    (APB1_PERIPH_BASE + 0x10000)
#define AHB_PERIPH_BASE     (APB2_PERIPH_BASE + 0x8000)

#define RCC_BASE            (AHB_PERIPH_BASE + 0x9000)
#define RCC                 ((rcc_t *) RCC_BASE)


typedef struct {
    volatile uint32_t CR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t APB2RSTR;
    volatile uint32_t APB1RSTR;
    volatile uint32_t AHBENR;
    volatile uint32_t APB2ENR;
    volatile uint32_t APB1ENR;
    volatile uint32_t BDCR;
    volatile uint32_t CSR;
} rcc_t;
/* RCC macros*/
#define RCC_APB2ENR_IOPAEN  (1U << 2)
#define RCC_APB2ENR_IOPBEN  (RCC_APB2ENR_IOPAEN << 1)
#define RCC_APB2ENR_IOPCEN  (RCC_APB2ENR_IOPBEN << 1)
#define RCC_APB2ENR_IOPDEN  (RCC_APB2ENR_IOPCEN << 1)




#define GPIO_BASE           (APB2_PERIPH_BASE + 0x800)
#define GPIOA_BASE          (GPIO_BASE)
#define GPIOB_BASE          (GPIOA_BASE + 0x400)
#define GPIOC_BASE          (GPIOB_BASE + 0x400)
#define GPIOD_BASE          (GPIOC_BASE + 0x400)
#define GPIOE_BASE          (GPIOD_BASE + 0x400)
#define GPIOF_BASE          (GPIOE_BASE + 0x400)
#define GPIOG_BASE          (GPIOF_BASE + 0x400)
#define GPIOA               ((gpio_t*) GPIOA_BASE)
#define GPIOB               ((gpio_t*) GPIOB_BASE)
#define GPIOC               ((gpio_t*) GPIOC_BASE)
#define GPIOD               ((gpio_t*) GPIOD_BASE)

typedef struct {
    volatile uint32_t CRL;
    volatile uint32_t CRH;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t BRR;
    volatile uint32_t LCKR;
} gpio_t;

typedef enum {
    GPIO_INPUT = 0b00,
    GPIO_OUTPUT_10MHZ,
    GPIO_OUTPUT_2MHZ,
    GPIO_OUTPUT_50MHZ,
    GPIO_OUTPUT = GPIO_OUTPUT_2MHZ,
} MODE;
typedef enum {
    GPIO_ANALOG = 0b00,
    GPIO_PULL = 0b10
} CNF;
typedef enum {
    PIN_0,
    PIN_1,
    PIN_2,
    PIN_3,
    PIN_4,
    PIN_5,
    PIN_6,
    PIN_7,
    PIN_8,
    PIN_9,
    PIN_10,
    PIN_11,
    PIN_12,
    PIN_13,
    PIN_14,
    PIN_15,
    PIN_COUNT,
} PIN;

/* GPIO Macros */
#define GPIO_CR_REGISTER(gpio, pin)     ((pin) > 7 ? &(gpio->CRH) : &(gpio->CRL))
#define GPIO_CNF_MASK(pin)              (0b11 << (((pin % 8) * 4) + 2))
#define GPIO_MODE_MASK(pin)             (0b11 << ((pin % 8) * 4))
#define GPIO_CNF_PINS(pin)              (((pin % 8) * 4) + 2)
#define GPIO_MODE_PINS(pin)             ((pin % 8) * 4)
#endif 
