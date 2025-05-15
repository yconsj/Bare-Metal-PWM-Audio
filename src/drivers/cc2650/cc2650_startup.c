#include<stdint.h>
#include "rcc_cc2650.h"

#define RAM_START   0x20000000U
#define RAM_SIZE    (20 * 1024U) // 128K RAM
#define RAM_END     ((RAM_START) + (RAM_SIZE))


/* define stack start */
#define STACK_START RAM_END
/* linker externs*/
extern uint32_t _etext, _sdata, _edata, _sbss, _ebss;
extern void main(void);

// Function Declarations (Signatures)
void Reset_Handler(void);
void HardFault_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVCall_Handler(void);
void DebugMonitor_Handler(void);
void PendSV_Handler(void);
//void SysTick_Handler(void);

void GPIO_Edge_Detect_Handler(void);
void I2C_Handler(void);
void RFCore_Packet_Engine_1_Handler(void);
void Unassigned_Handler(void);
void AON_RTC_Handler(void);
void UART0_Handler(void);
void UART1_Handler(void);
void SSI0_Handler(void);
void SSI1_Handler(void);
void RFCore_Packet_Engine_2_Handler(void);
void RFCore_Hardware_Handler(void);
void RF_Command_Acknowledge_Handler(void);
void I2S_Handler(void);
void Unassigned2_Handler(void);
void Watchdog_Timer_Handler(void);
void GPTimer_0A_Handler(void);
void GPTimer_0B_Handler(void);
void GPTimer_1A_Handler(void);
void GPTimer_1B_Handler(void);
void GPTimer_2A_Handler(void);
void GPTimer_2B_Handler(void);
void GPTimer_3A_Handler(void);
void GPTimer_3B_Handler(void);
void Crypto_Handler(void);
void uDMA_Software_Handler(void);
void uDMA_Error_Handler(void);
void Flash_Handler(void);
void Software_Event_0_Handler(void);
void AUX_Combined_Event_Handler(void);
void AON_Programmable_Event_Handler(void);
void Dynamic_Programmable_Event_Handler(void);
void AUX_Comparator_A_Handler(void);
void AUX_ADC_Handler(void);
void True_Random_Number_Generator_Handler(void);



const uint32_t vector[] __attribute__((section(".isr_vector"))) = {
    STACK_START,                // 0x00000000: Initial stack pointer value
    (uint32_t) &Reset_Handler,  // 0x00000004: Reset Handler
    0,                          // 0x00000008: Blank (Reserved)
    (uint32_t) &HardFault_Handler, // 0x0000000C: HardFault Handler
    (uint32_t) &BusFault_Handler,  // 0x00000010: BusFault Handler
    (uint32_t) &UsageFault_Handler, // 0x00000014: UsageFault Handler
    0,                          // 0x00000018: Blank (Reserved)
    0,                          // 0x0000001C: Blank (Reserved)
    0,                          // 0x00000020: Blank (Reserved)
    (uint32_t) &SVCall_Handler,    // 0x00000024: SVCall Handler
    (uint32_t) &DebugMonitor_Handler, // 0x00000028: Debug Monitor Handler
    0,                          // 0x0000002C: Blank (Reserved)
    (uint32_t) &PendSV_Handler,    // 0x00000030: PendSV Handler
    (uint32_t) &SysTick_Handler,   // 0x00000034: SysTick Handler
    (uint32_t) &GPIO_Edge_Detect_Handler, // 0x00000038: GPIO Edge Detect Handler
    (uint32_t) &I2C_Handler,        // 0x0000003C: I2C Handler
    (uint32_t) &RFCore_Packet_Engine_1_Handler, // 0x00000040: RF Core and Packet Engine 1 Handler
    (uint32_t) &Unassigned_Handler,  // 0x00000044: Unassigned Handler
    (uint32_t) &AON_RTC_Handler,     // 0x00000048: AON RTC Handler
    (uint32_t) &UART0_Handler,       // 0x0000004C: UART0 Handler
    (uint32_t) &UART1_Handler,       // 0x00000050: UART1 Handler
    (uint32_t) &SSI0_Handler,        // 0x00000054: SSI0 Handler
    (uint32_t) &SSI1_Handler,        // 0x00000058: SSI1 Handler
    (uint32_t) &RFCore_Packet_Engine_2_Handler, // 0x0000005C: RF Core and Packet Engine 2 Handler
    (uint32_t) &RFCore_Hardware_Handler, // 0x00000060: RF Core Hardware Handler
    (uint32_t) &RF_Command_Acknowledge_Handler, // 0x00000064: RF Command Acknowledge Handler
    (uint32_t) &I2S_Handler,         // 0x00000068: I2S Handler
    (uint32_t) &Unassigned2_Handler, // 0x0000006C: Unassigned Handler
    (uint32_t) &Watchdog_Timer_Handler, // 0x00000070: Watchdog Timer Handler
    (uint32_t) &GPTimer_0A_Handler, // 0x00000074: GPTimer 0A Handler
    (uint32_t) &GPTimer_0B_Handler, // 0x00000078: GPTimer 0B Handler
    (uint32_t) &GPTimer_1A_Handler, // 0x0000007C: GPTimer 1A Handler
    (uint32_t) &GPTimer_1B_Handler, // 0x00000080: GPTimer 1B Handler
    (uint32_t) &GPTimer_2A_Handler, // 0x00000084: GPTimer 2A Handler
    (uint32_t) &GPTimer_2B_Handler, // 0x00000088: GPTimer 2B Handler
    (uint32_t) &GPTimer_3A_Handler, // 0x0000008C: GPTimer 3A Handler
    (uint32_t) &GPTimer_3B_Handler, // 0x00000090: GPTimer 3B Handler
    (uint32_t) &Crypto_Handler,     // 0x00000094: Crypto Handler
    (uint32_t) &uDMA_Software_Handler, // 0x00000098: uDMA Software Handler
    (uint32_t) &uDMA_Error_Handler, // 0x0000009C: uDMA Error Handler
    (uint32_t) &Flash_Handler,      // 0x000000A0: Flash Handler
    (uint32_t) &Software_Event_0_Handler, // 0x000000A4: Software Event 0 Handler
    (uint32_t) &AUX_Combined_Event_Handler, // 0x000000A8: AUX Combined Event Handler
    (uint32_t) &AON_Programmable_Event_Handler, // 0x000000AC: AON Programmable Event Handler
    (uint32_t) &Dynamic_Programmable_Event_Handler, // 0x000000B0: Dynamic Programmable Event Handler
    (uint32_t) &AUX_Comparator_A_Handler, // 0x000000B4: AUX Comparator A Handler
    (uint32_t) &AUX_ADC_Handler,     // 0x000000B8: AUX ADC Handler
    (uint32_t) &True_Random_Number_Generator_Handler // 0x000000BC: True RNG Handler
};
void HardFault_Handler(void) {
    // HardFault handler implementation
    while (1);  // Infinite loop for error handling
}

void BusFault_Handler(void) {
    // BusFault handler implementation
    while (1);  // Infinite loop for error handling
}

void UsageFault_Handler(void) {
    // UsageFault handler implementation
    while (1);  // Infinite loop for error handling
}

void SVCall_Handler(void) {
    // SVCall handler implementation
    while (1);  // Infinite loop for error handling
}

void DebugMonitor_Handler(void) {
    // DebugMonitor handler implementation
    while (1);  // Infinite loop for error handling
}

void PendSV_Handler(void) {
    // PendSV handler implementation
    while (1);  // Infinite loop for error handling
}

/*void SysTick_Handler(void) {
    // SysTick handler implementation
    while (1);  // Infinite loop for error handling
}*/

// Interrupt Handlers
void GPIO_Edge_Detect_Handler(void) {
    while (1);  // Handle GPIO edge detect interrupt
}

void I2C_Handler(void) {
    while (1);  // Handle I2C interrupt
}

void RFCore_Packet_Engine_1_Handler(void) {
    while (1);  // Handle RF core packet engine 1 interrupt
}

void Unassigned_Handler(void) {
    while (1);  // Unassigned interrupt
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
        *pDst++ = 0;
    }

    // call main
    main();
}



// Provide weak default handlers for all interrupts you don't use
__attribute__((weak)) void AON_RTC_Handler(void)              { while(1); }
__attribute__((weak)) void UART0_Handler(void)                { while(1); }
__attribute__((weak)) void UART1_Handler(void)                { while(1); }
__attribute__((weak)) void SSI0_Handler(void)                 { while(1); }
__attribute__((weak)) void SSI1_Handler(void)                 { while(1); }
__attribute__((weak)) void RFCore_Packet_Engine_2_Handler(void){ while(1); }
__attribute__((weak)) void RFCore_Hardware_Handler(void)      { while(1); }
__attribute__((weak)) void RF_Command_Acknowledge_Handler(void){ while(1); }
__attribute__((weak)) void I2S_Handler(void)                  { while(1); }
__attribute__((weak)) void Unassigned2_Handler(void)          { while(1); }
__attribute__((weak)) void Watchdog_Timer_Handler(void)       { while(1); }
__attribute__((weak)) void GPTimer_0A_Handler(void)           { while(1); }
__attribute__((weak)) void GPTimer_0B_Handler(void)           { while(1); }
__attribute__((weak)) void GPTimer_1A_Handler(void)           { while(1); }
__attribute__((weak)) void GPTimer_1B_Handler(void)           { while(1); }
__attribute__((weak)) void GPTimer_2A_Handler(void)           { while(1); }
__attribute__((weak)) void GPTimer_2B_Handler(void)           { while(1); }
__attribute__((weak)) void GPTimer_3A_Handler(void)           { while(1); }
__attribute__((weak)) void GPTimer_3B_Handler(void)           { while(1); }
__attribute__((weak)) void Crypto_Handler(void)               { while(1); }
__attribute__((weak)) void uDMA_Software_Handler(void)        { while(1); }
__attribute__((weak)) void uDMA_Error_Handler(void)           { while(1); }
__attribute__((weak)) void Flash_Handler(void)                { while(1); }
__attribute__((weak)) void Software_Event_0_Handler(void)     { while(1); }
__attribute__((weak)) void AUX_Combined_Event_Handler(void)   { while(1); }
__attribute__((weak)) void AON_Programmable_Event_Handler(void){ while(1); }
__attribute__((weak)) void Dynamic_Programmable_Event_Handler(void){ while(1); }
__attribute__((weak)) void AUX_Comparator_A_Handler(void)     { while(1); }
__attribute__((weak)) void AUX_ADC_Handler(void)              { while(1); }
__attribute__((weak)) void True_Random_Number_Generator_Handler(void){ while(1); }
