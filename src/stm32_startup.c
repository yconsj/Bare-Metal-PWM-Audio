#include<stdint.h>

#define RAM_START   0x20000000U
#define RAM_SIZE    (128 + 1024) // 128K RAM
#define RAM_END     ((RAM_START) + (RAM_SIZE))

/* define stack start */
#define STACK_START RAM_END

/* linker externs*/
extern uint32_t _etext, _sdata, _edata, _sbss, _ebss;


int main(void);

void Reset_Handler(void);
void NMI_handler(void)                  __attribute__((alias("Default_Handler")));
void HardFault_Handler(void)            __attribute__((alias("Default_Handler")));
void MemManager_Handler(void)           __attribute__((alias("Default_Handler")));
void BusFault_Handler(void)             __attribute__((alias("Default_Handler")));
void UsageFault_Handler(void)           __attribute__((alias("Default_Handler")));
void SVCall_Handler(void)               __attribute__((alias("Default_Handler")));
void DebugMonitor_Handler(void)         __attribute__((alias("Default_Handler")));
void PendSV_Handler(void)               __attribute__((alias("Default_Handler")));
void SysTick_Handler(void)              __attribute__((alias("Default_Handler")));

void WWDG_IRQHandler(void)              __attribute__((alias("Default_Handler")));
void PVD_IRQHandler(void)               __attribute__((alias("Default_Handler")));
void TAMPER_IRQHandler(void)            __attribute__((alias("Default_Handler")));
void RTC_IRQHandler(void)               __attribute__((alias("Default_Handler")));
void FLASH_IRQHandler(void)             __attribute__((alias("Default_Handler")));
void RCC_IRQHandler(void)               __attribute__((alias("Default_Handler")));
void EXTI0_IRQHandler(void)             __attribute__((alias("Default_Handler")));
void EXTI1_IRQHandler(void)             __attribute__((alias("Default_Handler")));
void EXTI2_IRQHandler(void)             __attribute__((alias("Default_Handler")));
void EXTI3_IRQHandler(void)             __attribute__((alias("Default_Handler")));
void EXTI4_IRQHandler(void)             __attribute__((alias("Default_Handler")));
void DMA1_C1_IRQHandler(void)           __attribute__((alias("Default_Handler")));
void DMA1_C2_IRQHandler(void)           __attribute__((alias("Default_Handler")));
void DMA1_C3_IRQHandler(void)           __attribute__((alias("Default_Handler")));
void DMA1_C4_IRQHandler(void)           __attribute__((alias("Default_Handler")));
void DMA1_C5_IRQHandler(void)           __attribute__((alias("Default_Handler")));
void DMA1_C6_IRQHandler(void)           __attribute__((alias("Default_Handler")));
void DMA1_C7_IRQHandler(void)           __attribute__((alias("Default_Handler")));
void ADC1_2_IRQHandler(void)            __attribute__((alias("Default_Handler")));
void CAN1_TX_IRQHandler(void)           __attribute__((alias("Default_Handler")));
void CAN1_RX0_IRQHandler(void)          __attribute__((alias("Default_Handler")));
void CAN1_RX1_IRQHandler(void)          __attribute__((alias("Default_Handler")));
void CAN1_SCE_IRQHandler(void)          __attribute__((alias("Default_Handler")));
void EXIT9_5_IRQHandler(void)           __attribute__((alias("Default_Handler")));
void TIM1_BRK_IRQHandler(void)          __attribute__((alias("Default_Handler")));
void TIM1_UP_IRQHandler(void)           __attribute__((alias("Default_Handler")));
void TIM1_TRG_COM_IRQHandler(void)      __attribute__((alias("Default_Handler")));
void TIM1_CC_IRQHandler(void)           __attribute__((alias("Default_Handler")));
void TIM2_IRQHandler(void)              __attribute__((alias("Default_Handler")));
void TIM3_IRQHandler(void)              __attribute__((alias("Default_Handler")));
void TIM4_IRQHandler(void)              __attribute__((alias("Default_Handler")));
void I2C1_EV_IRQHandler(void)           __attribute__((alias("Default_Handler")));
void I2C1_ER_IRQHandler(void)           __attribute__((alias("Default_Handler")));
void I2C2_EV_IRQHandler(void)           __attribute__((alias("Default_Handler")));
void I2C2_ER_IRQHandler(void)           __attribute__((alias("Default_Handler")));
void SPI1_IRQHandler(void)              __attribute__((alias("Default_Handler")));
void SPI2_IRQHandler(void)              __attribute__((alias("Default_Handler")));
void USART1_IRQHandler(void)            __attribute__((alias("Default_Handler")));
void USART2_IRQHandler(void)            __attribute__((alias("Default_Handler")));
void USART3_IRQHandler(void)            __attribute__((alias("Default_Handler")));
void EXTI15_10_IRQHandler(void)         __attribute__((alias("Default_Handler")));
void RTCAlarm_IRQHandler(void)          __attribute__((alias("Default_Handler")));
void OTG_FS_WKUP_IRQHandler(void)       __attribute__((alias("Default_Handler")));
void TIM5_IRQHandler(void)              __attribute__((alias("Default_Handler")));
void UART4_IRQHandler(void)             __attribute__((alias("Default_Handler")));
void UART5_IRQHandler(void)             __attribute__((alias("Default_Handler")));
void TIM6_IRQHandler(void)              __attribute__((alias("Default_Handler")));
void TIM7_IRQHandler(void)              __attribute__((alias("Default_Handler")));
void DMA2_Channel1_IRQHandler(void)     __attribute__((alias("Default_Handler")));
void DMA2_Channel2_IRQHandler(void)     __attribute__((alias("Default_Handler")));
void DMA2_Channel3_IRQHandler(void)     __attribute__((alias("Default_Handler")));
void DMA2_Channel4_IRQHandler(void)     __attribute__((alias("Default_Handler")));
void DMA2_Channel5_IRQHandler(void)     __attribute__((alias("Default_Handler")));
void ETH_IRQHandler(void)               __attribute__((alias("Default_Handler")));
void ETH_WKUP_IRQHandler(void)          __attribute__((alias("Default_Handler")));
void CAN2_TX_IRQHandler(void)           __attribute__((alias("Default_Handler")));
void CAN2_RX0_IRQHandler(void)          __attribute__((alias("Default_Handler")));
void CAN2_RX1_IRQHandler(void)          __attribute__((alias("Default_Handler")));
void CAN2_SCE_IRQHandler(void)          __attribute__((alias("Default_Handler")));
void OTG_FS_IRQHandler(void)            __attribute__((alias("Default_Handler")));




uint32_t vectors[] __attribute__((section (".isr_vector"))) = {
    STACK_START,
    (uint32_t) &Reset_Handler,
    (uint32_t) &NMI_handler,
    (uint32_t) &HardFault_Handler,       
    (uint32_t) &MemManager_Handler,      
    (uint32_t) &BusFault_Handler,         
    (uint32_t) &UsageFault_Handler,  
    0,   
    0,
    0,
    0,
    0,
    (uint32_t) &SVCall_Handler,          
    (uint32_t) &DebugMonitor_Handler,  
    0,  
    (uint32_t) &PendSV_Handler,           
    (uint32_t) &SysTick_Handler,          
    (uint32_t) &WWDG_IRQHandler,          
    (uint32_t) &PVD_IRQHandler,          
    (uint32_t) &TAMPER_IRQHandler,   
    (uint32_t) &RTC_IRQHandler,          
    (uint32_t) &FLASH_IRQHandler,        
    (uint32_t) &RCC_IRQHandler,         
    (uint32_t) &EXTI0_IRQHandler,        
    (uint32_t) &EXTI1_IRQHandler,        
    (uint32_t) &EXTI2_IRQHandler,        
    (uint32_t) &EXTI3_IRQHandler,        
    (uint32_t) &EXTI4_IRQHandler,        
    (uint32_t) &EXTI0_IRQHandler,        
    (uint32_t) &DMA1_C1_IRQHandler,      
    (uint32_t) &DMA1_C2_IRQHandler,      
    (uint32_t) &DMA1_C3_IRQHandler,      
    (uint32_t) &DMA1_C4_IRQHandler,      
    (uint32_t) &DMA1_C5_IRQHandler,      
    (uint32_t) &DMA1_C6_IRQHandler,      
    (uint32_t) &DMA1_C7_IRQHandler,      
    (uint32_t) &ADC1_2_IRQHandler,      
    (uint32_t) &CAN1_TX_IRQHandler,      
    (uint32_t) &CAN1_RX0_IRQHandler,      
    (uint32_t) &CAN1_RX1_IRQHandler,      
    (uint32_t) &CAN1_SCE_IRQHandler,      
    (uint32_t) &EXIT9_5_IRQHandler,      
    (uint32_t) &TIM1_BRK_IRQHandler,     
    (uint32_t) &TIM1_UP_IRQHandler,      
    (uint32_t) &TIM1_TRG_COM_IRQHandler,
    (uint32_t) &TIM1_CC_IRQHandler,       
    (uint32_t) &TIM2_IRQHandler,          
    (uint32_t) &TIM3_IRQHandler,          
    (uint32_t) &TIM4_IRQHandler,          
    (uint32_t) &I2C1_EV_IRQHandler,       
    (uint32_t) &I2C1_ER_IRQHandler,       
    (uint32_t) &I2C2_EV_IRQHandler,       
    (uint32_t) &I2C2_ER_IRQHandler,       
    (uint32_t) &SPI1_IRQHandler,         
    (uint32_t) &SPI2_IRQHandler,         
    (uint32_t) &USART1_IRQHandler,        
    (uint32_t) &USART2_IRQHandler,        
    (uint32_t) &USART3_IRQHandler,        
    (uint32_t) &EXTI15_10_IRQHandler,     
    (uint32_t) &RTCAlarm_IRQHandler,      
    (uint32_t) &OTG_FS_WKUP_IRQHandler, 
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    (uint32_t) &TIM5_IRQHandler,         
    (uint32_t) &UART4_IRQHandler,         
    (uint32_t) &UART5_IRQHandler,        
    (uint32_t) &TIM6_IRQHandler,       
    (uint32_t) &TIM7_IRQHandler,   
    (uint32_t) &DMA2_Channel1_IRQHandler, 
    (uint32_t) &DMA2_Channel2_IRQHandler, 
    (uint32_t) &DMA2_Channel3_IRQHandler, 
    (uint32_t) &DMA2_Channel4_IRQHandler, 
    (uint32_t) &DMA2_Channel5_IRQHandler, 
    (uint32_t) &ETH_IRQHandler,           
    (uint32_t) &ETH_WKUP_IRQHandler,     
    (uint32_t) &CAN2_TX_IRQHandler,      
    (uint32_t) &CAN2_RX0_IRQHandler,     
    (uint32_t) &CAN2_RX1_IRQHandler,     
    (uint32_t) &CAN2_SCE_IRQHandler,     
    (uint32_t) &OTG_FS_IRQHandler,            
};

void Default_Handler(void){
    while(1);
}

void Reset_Handler(void){
    // copy .data seection to RAM
    uint32_t size = &_edata - &_sdata;

    uint8_t* pDst = (uint8_t*)&_sdata; // ram
    uint8_t* pSrc = (uint8_t*)&_etext; // flash


    for(uint32_t i = 0 ; i<size ;i++){
        *pDst++ = *pSrc++;
    }
    // init the .bss section to 0 in RAM
    size = &_ebss - &_sbss;
    pDst = (uint8_t*) &_sbss;
    for(uint32_t i = 0 ; i<size ;i++){
        *pDst = 0;
    }

    // call init function of std lib
    // call main
    main();
}