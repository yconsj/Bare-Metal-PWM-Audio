#include "debug_cc2650.h"
#include <stdbool.h>
void __error__	(	char * 	pcFilename,
    uint32_t 	ui32Line ) {
    // Error catching.
    // User can implement custom error handling for failing ASSERTs.
    // Setting breakpoint here allows tracing of the failing ASSERT.
    while( true );
}	