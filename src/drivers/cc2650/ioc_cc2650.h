#include <stdint.h>
#include <assert.h>
#include "gpio_cc2650.h"
#include "debug_cc2650.h"
#include "hw_memmap_cc2650.h"
#include "hw_types_cc2650.h"
#include "hw_ioc_cc2650.h"
#include "debug_cc2650.h"

//*****************************************************************************
//
// Number of IOs (max. total of 32)
//
//*****************************************************************************
#define NUM_IO_MAX 32

//*****************************************************************************
//
// The following fields are IO Id for the IOC module
//
//*****************************************************************************
#define IOID_0                  0x00000000  // IO Id 0
#define IOID_1                  0x00000001  // IO Id 1
#define IOID_2                  0x00000002  // IO Id 2
#define IOID_3                  0x00000003  // IO Id 3
#define IOID_4                  0x00000004  // IO Id 4
#define IOID_5                  0x00000005  // IO Id 5
#define IOID_6                  0x00000006  // IO Id 6
#define IOID_7                  0x00000007  // IO Id 7
#define IOID_8                  0x00000008  // IO Id 8
#define IOID_9                  0x00000009  // IO Id 9
#define IOID_10                 0x0000000A  // IO Id 10
#define IOID_11                 0x0000000B  // IO Id 11
#define IOID_12                 0x0000000C  // IO Id 12
#define IOID_13                 0x0000000D  // IO Id 13
#define IOID_14                 0x0000000E  // IO Id 14
#define IOID_15                 0x0000000F  // IO Id 15
#define IOID_16                 0x00000010  // IO Id 16
#define IOID_17                 0x00000011  // IO Id 17
#define IOID_18                 0x00000012  // IO Id 18
#define IOID_19                 0x00000013  // IO Id 19
#define IOID_20                 0x00000014  // IO Id 20
#define IOID_21                 0x00000015  // IO Id 21
#define IOID_22                 0x00000016  // IO Id 22
#define IOID_23                 0x00000017  // IO Id 23
#define IOID_24                 0x00000018  // IO Id 24
#define IOID_25                 0x00000019  // IO Id 25
#define IOID_26                 0x0000001A  // IO Id 26
#define IOID_27                 0x0000001B  // IO Id 27
#define IOID_28                 0x0000001C  // IO Id 28
#define IOID_29                 0x0000001D  // IO Id 29
#define IOID_30                 0x0000001E  // IO Id 30
#define IOID_31                 0x0000001F  // IO Id 31
#define IOID_UNUSED             0xFFFFFFFF  // Unused IO Id

#define IOC_IOID_MASK           0x000000FF  // IOC IO Id bit mask

//*****************************************************************************
//
// Number of IO ports
//
//*****************************************************************************
#define NUM_IO_PORTS 56

//*****************************************************************************
//
// IOC Peripheral Port Mapping
//
//*****************************************************************************
#define IOC_PORT_GPIO             0x00000000  // Default general purpose IO usage
#define IOC_PORT_AON_CLK32K       0x00000007  // AON External 32kHz clock
#define IOC_PORT_AUX_IO           0x00000008  // AUX IO Pin
#define IOC_PORT_MCU_SSI0_RX      0x00000009  // MCU SSI0 Receive Pin
#define IOC_PORT_MCU_SSI0_TX      0x0000000A  // MCU SSI0 Transmit Pin
#define IOC_PORT_MCU_SSI0_FSS     0x0000000B  // MCU SSI0 FSS Pin
#define IOC_PORT_MCU_SSI0_CLK     0x0000000C  // MCU SSI0 Clock Pin
#define IOC_PORT_MCU_I2C_MSSDA    0x0000000D  // MCU I2C Data Pin
#define IOC_PORT_MCU_I2C_MSSCL    0x0000000E  // MCU I2C Clock Pin
#define IOC_PORT_MCU_UART0_RX     0x0000000F  // MCU UART0 Receive Pin
#define IOC_PORT_MCU_UART0_TX     0x00000010  // MCU UART0 Transmit Pin
#define IOC_PORT_MCU_UART0_CTS    0x00000011  // MCU UART0 Clear To Send Pin
#define IOC_PORT_MCU_UART0_RTS    0x00000012  // MCU UART0 Request To Send Pin
#define IOC_PORT_MCU_PORT_EVENT0  0x00000017  // MCU PORT EVENT 0
#define IOC_PORT_MCU_PORT_EVENT1  0x00000018  // MCU PORT EVENT 1
#define IOC_PORT_MCU_PORT_EVENT2  0x00000019  // MCU PORT EVENT 2
#define IOC_PORT_MCU_PORT_EVENT3  0x0000001A  // MCU PORT EVENT 3
#define IOC_PORT_MCU_PORT_EVENT4  0x0000001B  // MCU PORT EVENT 4
#define IOC_PORT_MCU_PORT_EVENT5  0x0000001C  // MCU PORT EVENT 5
#define IOC_PORT_MCU_PORT_EVENT6  0x0000001D  // MCU PORT EVENT 6
#define IOC_PORT_MCU_PORT_EVENT7  0x0000001E  // MCU PORT EVENT 7
#define IOC_PORT_MCU_SWV          0x00000020  // Serial Wire Viewer
#define IOC_PORT_MCU_SSI1_RX      0x00000021  // MCU SSI1 Receive Pin
#define IOC_PORT_MCU_SSI1_TX      0x00000022  // MCU SSI1 Transmit Pin
#define IOC_PORT_MCU_SSI1_FSS     0x00000023  // MCU SSI1 FSS Pin
#define IOC_PORT_MCU_SSI1_CLK     0x00000024  // MCU SSI1 Clock Pin
#define IOC_PORT_MCU_I2S_AD0      0x00000025  // MCU I2S Data Pin 0
#define IOC_PORT_MCU_I2S_AD1      0x00000026  // MCU I2S Data Pin 1
#define IOC_PORT_MCU_I2S_WCLK     0x00000027  // MCU I2S Frame/Word Clock
#define IOC_PORT_MCU_I2S_BCLK     0x00000028  // MCU I2S Bit Clock
#define IOC_PORT_MCU_I2S_MCLK     0x00000029  // MCU I2S Master clock 2
#define IOC_PORT_RFC_TRC          0x0000002E  // RF Core Tracer
#define IOC_PORT_RFC_GPO0         0x0000002F  // RC Core Data Out Pin 0
#define IOC_PORT_RFC_GPO1         0x00000030  // RC Core Data Out Pin 1
#define IOC_PORT_RFC_GPO2         0x00000031  // RC Core Data Out Pin 2
#define IOC_PORT_RFC_GPO3         0x00000032  // RC Core Data Out Pin 3
#define IOC_PORT_RFC_GPI0         0x00000033  // RC Core Data In Pin 0
#define IOC_PORT_RFC_GPI1         0x00000034  // RC Core Data In Pin 1
#define IOC_PORT_RFC_SMI_DL_OUT   0x00000035  // RF Core SMI Data Link Out
#define IOC_PORT_RFC_SMI_DL_IN    0x00000036  // RF Core SMI Data Link in
#define IOC_PORT_RFC_SMI_CL_OUT   0x00000037  // RF Core SMI Command Link Out
#define IOC_PORT_RFC_SMI_CL_IN    0x00000038  // RF Core SMI Command Link In

//*****************************************************************************
//
// Defines for enabling/disabling an IO
//
//*****************************************************************************
#define IOC_SLEW_ENABLE         0x00001000
#define IOC_SLEW_DISABLE        0x00000000
#define IOC_INPUT_ENABLE        0x20000000
#define IOC_INPUT_DISABLE       0x00000000
#define IOC_HYST_ENABLE         0x40000000
#define IOC_HYST_DISABLE        0x00000000

//*****************************************************************************
//
// Defines that can be used to set the shutdown mode of an IO
//
//*****************************************************************************
#define IOC_NO_WAKE_UP          0x00000000
#define IOC_WAKE_ON_LOW         0x10000000
#define IOC_WAKE_ON_HIGH        0x18000000

//*****************************************************************************
//
// Defines that can be used to set the IO Mode of an IO
//
//*****************************************************************************
#define IOC_IOMODE_NORMAL       0x00000000  // Normal Input/Output
#define IOC_IOMODE_INV          0x01000000  // Inverted Input/Output
#define IOC_IOMODE_OPEN_DRAIN_NORMAL \
                                0x04000000  // Open Drain, Normal Input/Output
#define IOC_IOMODE_OPEN_DRAIN_INV \
                                0x05000000  // Open Drain, Inverted
                                            // Input/Output
#define IOC_IOMODE_OPEN_SRC_NORMAL \
                                0x06000000  // Open Source, Normal Input/Output
#define IOC_IOMODE_OPEN_SRC_INV \
                                0x07000000  // Open Source, Inverted
                                            // Input/Output

//*****************************************************************************
//
// Defines that can be used to set the edge detection on an IO
//
//*****************************************************************************
#define IOC_NO_EDGE             0x00000000  // No edge detection
#define IOC_FALLING_EDGE        0x00010000  // Edge detection on falling edge
#define IOC_RISING_EDGE         0x00020000  // Edge detection on rising edge
#define IOC_BOTH_EDGES          0x00030000  // Edge detection on both edges
#define IOC_INT_ENABLE          0x00040000  // Enable interrupt on edge detect
#define IOC_INT_DISABLE         0x00000000  // Disable interrupt on edge detect
#define IOC_INT_M               0x00070000  // Int config mask

//*****************************************************************************
//
// Defines that be used to set pull on an IO
//
//*****************************************************************************
#define IOC_NO_IOPULL           0x00006000  // No IO pull
#define IOC_IOPULL_UP           0x00004000  // Pull up
#define IOC_IOPULL_DOWN         0x00002000  // Pull down
#define IOC_IOPULL_M            0x00006000  // Pull config mask
#define IOC_IOPULL_M            0x00006000

//*****************************************************************************
//
// Defines that can be used to select the drive strength of an IO
//
//*****************************************************************************
#define IOC_CURRENT_2MA         0x00000000  // 2mA drive strength
#define IOC_CURRENT_4MA         0x00000400  // 4mA drive strength
#define IOC_CURRENT_8MA         0x00000800  // 4 or 8mA drive strength

#define IOC_STRENGTH_AUTO       0x00000000  // Automatic Drive Strength
                                            // (2/4/8 mA @ VVDS)
#define IOC_STRENGTH_MAX        0x00000300  // Maximum Drive Strength
                                            // (2/4/8 mA @ 1.8V)
#define IOC_STRENGTH_MED        0x00000200  // Medium Drive Strength
                                            // (2/4/8 mA @ 2.5V)
#define IOC_STRENGTH_MIN        0x00000100  // Minimum Drive Strength
                                            // (2/4/8 mA @ 3.3V)

//*****************************************************************************
//
// Defines for standard IO setup
//
//*****************************************************************************
#define IOC_STD_INPUT           (IOC_CURRENT_2MA | IOC_STRENGTH_AUTO |      \
                                 IOC_NO_IOPULL | IOC_SLEW_DISABLE |         \
                                 IOC_HYST_DISABLE | IOC_NO_EDGE |           \
                                 IOC_INT_DISABLE | IOC_IOMODE_NORMAL |      \
                                 IOC_NO_WAKE_UP | IOC_INPUT_ENABLE )
#define IOC_STD_OUTPUT          (IOC_CURRENT_2MA | IOC_STRENGTH_AUTO |      \
                                 IOC_NO_IOPULL | IOC_SLEW_DISABLE |         \
                                 IOC_HYST_DISABLE | IOC_NO_EDGE |           \
                                 IOC_INT_DISABLE | IOC_IOMODE_NORMAL |      \
                                 IOC_NO_WAKE_UP | IOC_INPUT_DISABLE )



void IOCIOPortIdSet(uint32_t ui32IOId, uint32_t ui32PortId)
{
    uint32_t ui32IOReg;
    uint32_t ui32Config;

    // Check the arguments.
    ASSERT(ui32IOId <= IOID_31);
    ASSERT(ui32PortId <= IOC_PORT_RFC_GPI1);

    // Get the register address.
    ui32IOReg = IOC_BASE + ( ui32IOId << 2 );

    // Configure the IO.
    ui32Config = HWREG(ui32IOReg);
    ui32Config &= ~IOC_IOCFG0_PORT_ID_M;
    HWREG(ui32IOReg) = ui32Config | ui32PortId;
}

void IOCPortConfigureSet(uint32_t ui32IOId, uint32_t ui32PortId,
                    uint32_t ui32IOConfig)
{
    uint32_t ui32Reg;

    // Check the arguments.
    ASSERT(ui32IOId <= IOID_31);
    ASSERT(ui32PortId <= IOC_PORT_RFC_GPI1);

    // Get the register address.
    ui32Reg = IOC_BASE + ( ui32IOId << 2 );

    // Configure the port.
    HWREG(ui32Reg) = ui32IOConfig | ui32PortId;
}

void IOCPinTypeGpioOutput(uint32_t ui32IOId)
{
    // Check the arguments.
    ASSERT(ui32IOId <= IOID_31);

    // Setup the IO for standard input.
    IOCPortConfigureSet(ui32IOId, IOC_PORT_GPIO, IOC_STD_OUTPUT);

    // Enable output mode in the GPIO module.
    GPIO_setOutputEnableDio(ui32IOId, GPIO_OUTPUT_ENABLE);
}

void IOCPinTypeGpioInput(uint32_t ui32IOId)
{
     //
     // Check the arguments.
     //
     ASSERT(ui32IOId <= IOID_31);
 
    //
    // Setup the IO for standard input.
    //
    IOCPortConfigureSet(ui32IOId, IOC_PORT_GPIO, IOC_STD_INPUT);

    //
    // Enable input mode in the GPIO module.
    //
    GPIO_setOutputEnableDio(ui32IOId, GPIO_OUTPUT_DISABLE);
}