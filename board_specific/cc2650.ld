/* Linker script for TI LAUNCHPADXL CC2650 (128 KB Flash, 20 KB RAM) */
MEMORY
{
    FLASH(rx):ORIGIN = 0x00000000, LENGTH = 128K
    RAM(rwx):ORIGIN = 0x20000000, LENGTH = 20K
}

ENTRY(Reset_Handler)

SECTIONS
{
    /* Code and read-only data */
    .text : {
        *(.isr_vector)   /* Interrupt vector table */
        *(.text)     /* Program code */
        *(.rodata)   /* Read-only data */
        . = ALIGN(4);
        _etext = .;
    } > FLASH

    /* Initialized data */
    .data : {
        _sdata = .;
        *(.data)
        . = ALIGN(4);
        _edata = .;
    } > RAM AT> FLASH

    /* Uninitialized data */
    .bss : {
        _sbss = .;
        __bss_start__ = _sbss;
        *(.bss)
        *(COMMON)
        . = ALIGN(4);
        _ebss = .;
        __bss_end__ = _ebss;
    } > RAM
}