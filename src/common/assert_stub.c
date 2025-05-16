#include <stdint.h>
#include "assert_stub.h"

// This is the function that assert() expects to exist.
void __assert_func(const char *file, int line, const char *func, const char *failedexpr) {
    // Optionally you can output file/line/expr somewhere if you have UART etc.

    // Otherwise just enter an infinite loop (safe for now)
    while (1) {
        //__asm__("bkpt #0"); // Trigger a breakpoint for a debugger if connected
        __asm(" .word 0xBE00");
    }
}
