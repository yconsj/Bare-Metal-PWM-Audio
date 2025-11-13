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
#define RCC_APB1ENR_USART2EN (1U << 17)

/* GPIO */
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
    GPIO_GP_OUTPUT_PP,
    GPIO_GP_OUTPUT_OD,
    GPIO_AF_OUTPUT_PP,
    GPIO_AF_OUTPUT_OD
} GPIO_OUTPUT_CONFIG;

typedef enum {
    GPIO_MODE_INPUT_ANALOG,
    GPIO_MODE_INPUT_FLOAT,
    GPIO_MODE_INPUT_PP
} GPIO_INPUT_CONFIG;

typedef enum {
    GPIO_OUTPUT_SPEED_10MHZ = 1,
    GPIO_OUTPUT_SPEED_2MHZ,
    GPIO_OUTPUT_SPEED_50MHZ
} GPIO_SPEED;

typedef enum {
    GPIO_INPUT,
    GPIO_OUTPUT
} GPIO_MODE;




#define GPIO_CR_REGISTER(gpio, pin)     ((pin) > 7 ? &(gpio->CRH) : &(gpio->CRL))
#define GPIO_CNF_MASK(pin)              (0b11 << (((pin % 8) * 4) + 2))
#define GPIO_MODE_MASK(pin)             (0b11 << ((pin % 8) * 4))
#define GPIO_CNF_PINS(pin)              (((pin % 8) * 4) + 2)
#define GPIO_MODE_PINS(pin)             ((pin % 8) * 4)

/* AFIO */
#define AFIO_BASE           (APB2_PERIPH_BASE) // AFIO starts at APB2
#define AFIO               ((afio_t*) AFIO_BASE)

typedef struct {
    volatile uint32_t EVCR;
    volatile uint32_t MAPR;
    volatile uint32_t EXTICR1;
    volatile uint32_t EXTICR2;
    volatile uint32_t EXTICR3;
    volatile uint32_t EXTICR4;
    volatile uint32_t MAPR2;
} afio_t;


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

/* UART and USART*/
#define USART2_BASE (APB1_PERIPH_BASE + 0x00004400)

typedef struct
{
    volatile uint32_t SR;
    volatile uint32_t DR;
    volatile uint32_t BRR;
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t CR3;
    volatile uint32_t GTPR;

} USART_t;

#define USART2  ((USART_t*) USART2_BASE)

/* USART Macros */

// SR
#define USART_SR_PE     (1U << 0)
#define USART_SR_FE     (1U << 1)
#define USART_SR_NE     (1U << 2)
#define USART_SR_CRE    (1U << 3)
#define USART_SR_IDLE   (1U << 4)
#define USART_SR_RXNE   (1U << 5)
#define USART_SR_TC     (1U << 6)
#define USART_SR_TXE    (1U << 7)
#define USART_SR_LBD    (1U << 8)
#define USART_SR_CTR    (1U << 9)

// CR1
#define USART_CR1_SBK       (1U << 0)
#define USART_CR1_RWU       (1U << 1)
#define USART_CR1_RE        (1U << 2)
#define USART_CR1_TE        (1U << 3)
#define USART_CR1_IDLEIE    (1U << 4)
#define USART_CR1_RXNEIE    (1U << 5)
#define USART_CR1_TCIE      (1U << 6)
#define USART_CR1_TXEIE     (1U << 7)
#define USART_CR1_PEIE      (1U << 8)
#define USART_CR1_PS        (1U << 9)
#define USART_CR1_PCE       (1U << 10)
#define USART_CR1_WAKE      (1U << 11)
#define USART_CR1_M         (1U << 12)
#define USART_CR1_UE        (1U << 13)







/* Systick */
#define CLOCK_FREQ_MHZ 72 // TODO: validate clock freq

#define SYSTICK_BASE    (0xE000E010)
#define SYSTICK_CTRL    SYSTICK_BASE
#define SYSTICK_RELOAD  (SYSTICK_BASE + 0x4)
#define SYSTICK_VAl     (SYSTICK_BASE + 0x8)
#define SYSTICK_CALIB   (SYSTICK_BASE + 0x12)

#define SYSTICK         ((SysTick_t*) SYSTICK_BASE)
#define SYSTICK_CTRL_ENABLE             (1 << 0)
#define SYSTICK_CTRL_INTERRUPT_ENABLE   (1 << 1)
#define SYSTICK_CTRL_CLKSOURCE          (1 << 2)
#define SYSTICK_CTRL_COUNTFLAG          (1 << 16)
#define SYSTICK_CLOCK_FREQ_MHZ 9

typedef struct
{
    volatile uint32_t CTRL;
    volatile uint32_t LOAD;
    volatile uint32_t VAL;
    volatile uint32_t CALIB;
} SysTick_t;

#endif
