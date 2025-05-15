
#ifndef RCC_CC2650F103RB_H
#define RCC_CC2650F103RB_H
#include <stdint.h>
#include "..\..\hal\rcc_driver.h"
#include "registers_cc2650.h"
#include "gpio_cc2650.h"


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
} CC2650_rcc_t;

typedef struct
{
    volatile uint32_t CTRL;
    volatile uint32_t LOAD;
    volatile uint32_t VAL;
    volatile uint32_t CALIB;
} SysTick_t;


#define CC2650_CLOCK_FREQ_MHZ 48 // 72 // TODO: validate clock freq

#define CC2650_SYSTICK_BASE    (0xE000E010)
#define CC2650_SYSTICK_CTRL    CC2650_SYSTICK_BASE
#define CC2650_SYSTICK_RELOAD  (CC2650_SYSTICK_BASE + 0x4)
#define CC2650_SYSTICK_VAl     (CC2650_SYSTICK_BASE + 0x8)
#define CC2650_SYSTICK_CALIB   (CC2650_SYSTICK_BASE + 0x12)

#define CC2650_SYSTICK         ((SysTick_t*) CC2650_SYSTICK_BASE)
#define CC2650_SYSTICK_CTRL_ENABLE             (1 << 0)
#define CC2650_SYSTICK_CTRL_INTERRUPT_ENABLE   (1 << 1)
#define CC2650_SYSTICK_CTRL_CLKSOURCE          (1 << 2)
#define CC2650_SYSTICK_CTRL_COUNTFLAG          (1 << 16)



#endif