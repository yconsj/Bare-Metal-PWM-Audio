#include "uart_driver.h"
#include "rcc_driver.h"
#include "gpio_driver.h"
// UART2 is connected so st-link on PA2 and PA3
/*
Procedure:
1. Enable the USART by writing the UE bit in USART_CR1 register to 1.
2. Program the M bit in USART_CR1 to define the word length.
3. Program the number of stop bits in USART_CR2.
4. Select DMA enable (DMAT) in USART_CR3 if Multi buffer Communication is to take
place. Configure the DMA register as explained in multibuffer communication.
5. Select the desired baud rate using the USART_BRR register.
6. Set the TE bit in USART_CR1 to send an idle frame as first transmission.
7. Write the data to send in the USART_DR register (this clears the TXE bit). Repeat this
for each data to be transmitted in case of single buffer.
8. After writing the last data into the USART_DR register, wait until TC=1. This indicates
that the transmission of the last frame is complete. This is required for instance when
the USART is disabled or enters the Halt mode to avoid corrupting the last
transmission.
*/
void uart_init(void) {
    // Enable clocks
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;   // GPIOA clock
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN; // USART2 clock



    // Configure PA2 (TX) as AF push-pull, PA3 (RX) as input floating
    gpio_params_t PA2 = {
        .pin = PIN_2,
        .mode = GPIO_OUTPUT,
        .speed = GPIO_OUTPUT_SPEED_50MHZ,
        .output_config = GPIO_AF_OUTPUT_PP
    };
    gpio_params_t PA3 = {
        .pin = PIN_3,
        .mode = GPIO_INPUT,
        .input_config = GPIO_MODE_INPUT_FLOAT,
    };

    gpio_init(GPIOA, &PA2);
    gpio_init(GPIOA, &PA3);

    /*
    NOTE: Only USART1 is clocked with PCLK2 (72 MHz max). Other USARTs are clocked with
    PCLK1 (36 MHz max).
    */
    // Baud rate 19200 @ 36MHz PCLK1
    USART2->BRR = (117 << 4) | (3 & 0xF);

    // 8 data bits, 1 stop bit, no parity
    USART2->CR1 &= ~(1 << 12);

    // Enable transmitter and receiver
    USART2->CR1 |= (USART_CR1_TE | USART_CR1_RE);

    // Enable USART
    USART2->CR1 |= USART_CR1_UE;
}

void uart_putchar(char c) {
    while (!(USART2->SR & USART_SR_TXE)); // Wait until TX buffer empty
    USART2->DR = c;
    while (!(USART2->SR & USART_SR_TC));  // Wait for complete transmission
}


