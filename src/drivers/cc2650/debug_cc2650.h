
#include "../../common/assert_handler.h"
#include <stdint.h>
#include "assert_stub.h"

#define ASSERT(expr)	assert(	 	expr	)
// #define ASSERT(expr)	assert(	 	expr	)

void __error__	(	char * 	pcFilename,
    uint32_t 	ui32Line );

// #define ASSERT(expr) (expr)