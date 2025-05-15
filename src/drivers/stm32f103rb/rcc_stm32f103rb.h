
#ifndef RCC_STM32F103RB_H
#define RCC_STM32F103RB_H
#include <stdint.h>
#include "..\..\hal\rcc_driver.h"
#include "registers_stm32f103rb.h"
#include "gpio_stm32f103rb.h"


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
} STM32_rcc_t;

typedef struct
{
    volatile uint32_t CTRL;
    volatile uint32_t LOAD;
    volatile uint32_t VAL;
    volatile uint32_t CALIB;
} SysTick_t;


#define STM32_CLOCK_FREQ_MHZ 72 // TODO: validate clock freq

#define STM32_SYSTICK_BASE    (0xE000E010)
#define STM32_SYSTICK_CTRL    STM32_SYSTICK_BASE
#define STM32_SYSTICK_RELOAD  (STM32_SYSTICK_BASE + 0x4)
#define STM32_SYSTICK_VAL     (STM32_SYSTICK_BASE + 0x8)
#define STM32_SYSTICK_CALIB   (STM32_SYSTICK_BASE + 0xC)

#define STM32_SYSTICK         ((SysTick_t*) STM32_SYSTICK_BASE)
#define STM32_SYSTICK_CTRL_ENABLE             (1 << 0)
#define STM32_SYSTICK_CTRL_INTERRUPT_ENABLE   (1 << 1)
#define STM32_SYSTICK_CTRL_CLKSOURCE          (1 << 2)
#define STM32_SYSTICK_CTRL_COUNTFLAG          (1 << 16)



#endif