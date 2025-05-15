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
        PIN_16,
        PIN_17,
        PIN_18,
        PIN_19,
        PIN_20,
        PIN_21,
        PIN_22,
        PIN_23,
        PIN_24,
        PIN_25,
        PIN_26,
        PIN_27,
        PIN_28,
        PIN_29,
        PIN_30,
        PIN_31,
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
        // ...
    #else
    #endif

    #endif
    

#endif
