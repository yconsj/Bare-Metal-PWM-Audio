#ifndef PIN_H
    #define PIN_H

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

    typedef enum {
        GPIOA,
        GPIOB,
        GPIOC,
        GPIOD,
        GPIOE,
        GPIOF,
        GPIOG,
    } GPIO_PORT;


    typedef enum {
        GPIO_CNF_ANALOG,
        GPIO_CNF_PULL
    } GPIO_CNF;

    #ifdef stm32f103rb
        #include "..\drivers\stm32f103rb\pin_stm32f103rb.h"
    #else 
        #ifdef cc2650 
            #include "..\drivers\ticc2650\pin_cc2650.h"
    #else
    #endif

    #endif
    

#endif
