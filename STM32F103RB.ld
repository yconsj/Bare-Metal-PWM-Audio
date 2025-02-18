/* Linker script for STM32F103RB (128 KB Flash, 20 KB RAM) */
MEMORY
{
    FLASH(rx):ORIGIN = 0x08000000, LENGTH = 128K
    RAM(rwx):ORIGIN = 0x20000000, LENGTH = 20K
}

ENTRY (Reset_Handler)

SECTIONS
{
    /* Code and read-only data */
    .text : {
        *(.vectors)   /* Interrupt vector table */
        *(.text*)     /* Program code */
        *(.rodata*)   /* Read-only data */
        . = ALIGN(4);
        _etext = .;
    } > FLASH

    /* Initialized data */
    .data : {
        _sdata = .;
        *(.data*)
        . = ALIGN(4);
        _edata = .;
    } > RAM AT> FLASH

    /* Uninitialized data */
    .bss : {
        _sbss = .;
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        _ebss = .;
    } > RAM
}