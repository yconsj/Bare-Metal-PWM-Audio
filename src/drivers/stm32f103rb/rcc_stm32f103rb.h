
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

#endif