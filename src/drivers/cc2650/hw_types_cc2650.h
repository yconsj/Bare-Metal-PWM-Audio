#ifndef __HW_TYPES_H__
#define __HW_TYPES_H__

#include <stdint.h>
#include <stdbool.h>

#ifndef __STATIC_INLINE
#define __STATIC_INLINE static inline
#endif

// Macros for direct hardware access.
//
// If using these macros the programmer should be aware of any limitations to
// the address accessed i.e. if it supports word and/or byte access.
//
//*****************************************************************************
// Word (32 bit) access to address x
// Read example  : my32BitVar = HWREG(base_addr + offset) ;
// Write example : HWREG(base_addr + offset) = my32BitVar ;
#define HWREG(x)                                                              \
        (*((volatile unsigned long *)(x)))

// Half word (16 bit) access to address x
// Read example  : my16BitVar = HWREGH(base_addr + offset) ;
// Write example : HWREGH(base_addr + offset) = my16BitVar ;
#define HWREGH(x)                                                             \
        (*((volatile unsigned short *)(x)))

// Byte (8 bit) access to address x
// Read example  : my8BitVar = HWREGB(base_addr + offset) ;
// Write example : HWREGB(base_addr + offset) = my8BitVar ;
#define HWREGB(x)                                                             \
        (*((volatile unsigned char *)(x)))

// Macros for hardware access to bit-band supported addresses via the bit-band region.
//
// Macros calculate the corresponding address to access in the bit-band region
// based on the actual address of the memory/register and the bit number.
//
// Do NOT use these macros to access the bit-band region directly!
//
//*****************************************************************************
// Bit-band access to address x bit number b using word access (32 bit)
#define HWREGBITW(x, b)                                                       \
        HWREG(((unsigned long)(x) & 0xF0000000) | 0x02000000 |                \
              (((unsigned long)(x) & 0x000FFFFF) << 5) | ((b) << 2))

// Bit-band access to address x bit number b using half word access (16 bit)
#define HWREGBITH(x, b)                                                       \
        HWREGH(((unsigned long)(x) & 0xF0000000) | 0x02000000 |               \
               (((unsigned long)(x) & 0x000FFFFF) << 5) | ((b) << 2))

// Bit-band access to address x bit number b using byte access (8 bit)
#define HWREGBITB(x, b)                                                       \
        HWREGB(((unsigned long)(x) & 0xF0000000) | 0x02000000 |               \
               (((unsigned long)(x) & 0x000FFFFF) << 5) | ((b) << 2))

#endif