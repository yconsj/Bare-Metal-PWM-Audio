#ifndef RCC_DRIVER_H
#define RCC_DRIVER_H

#include "gpio_driver.h"


void rcc_peripheral_enable(GPIO_PORT port);
#ifdef stm32f103rb
    #include "../drivers/stm32f103rb/rcc_stm32f103rb.h"
#else 
    #ifdef cc2650 
        #include "../drivers/cc2650/rcc_cc2650.h"
#else
    // 
#endif

#endif

#endif
