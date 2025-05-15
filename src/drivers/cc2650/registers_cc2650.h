#ifndef REGISTERS_CC2650F103RB_H
#define REGISTERS_CC2650F103RB_H
#include <stdint.h>
#include "hw_memmap_cc2650.h"

#define CC2650_PERIPH_BASE         (0x40000000UL)
#define CC2650_GPIO_BASE           GPIO_BASE


#define CC2650_DOUT31_0            (CC2650_GPIO_BASE + 0x80) // Direct access
#define CC2650_DOUTSET31_0         (CC2650_GPIO_BASE + 0x90) // SET 
#define CC2650_DOUTCLR31_0         (CC2650_GPIO_BASE + 0xA0) // CLEAR
#define CC2650_DOUTTGL31_0         (CC2650_GPIO_BASE + 0xB0) // TOGGLE
#define CC2650_DIN31_0             (CC2650_GPIO_BASE + 0xC0) // Read input
#define CC2650_DOE31_0             (CC2650_GPIO_BASE + 0xC0) // Data output enable


#define CC2650_RCC_BASE            0//(CC2650_AHB_PERIPH_BASE + 0x9000)
#define CC2650_RCC                 0//((CC2650_rcc_t *) CC2650_RCC_BASE)



/* RCC macros*/
#define CC2650_RCC_APB2ENR_IOPAEN  0 //(1U << 2)
#define CC2650_RCC_APB2ENR_IOPBEN  0 //(CC2650_RCC_APB2ENR_IOPAEN << 1)
#define CC2650_RCC_APB2ENR_IOPCEN  0 //(CC2650_RCC_APB2ENR_IOPBEN << 1)
#define CC2650_RCC_APB2ENR_IOPDEN  0 //(CC2650_RCC_APB2ENR_IOPCEN << 1)


#endif 
