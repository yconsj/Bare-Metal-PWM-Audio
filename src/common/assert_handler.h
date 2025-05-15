#ifndef ASSERT_HANDLER_H
#define ASSERT_HANDLER_H
#include <assert.h>

/*#define ASSERT(expr) \
    do { \
        if (!(expr)) {\
            assert_handler();\
        }\
    } while(0);
*/

/*
void ASSERT(const int expr) {
    static_assert(expr,"assert");
}
*/
//#define ASSERT(expr) static_assert(expr, "assert")
void assert_handler(void);

#endif
