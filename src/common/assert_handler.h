#ifndef ASSERT_HANDLER_H
#define ASSERT_HANDLER_H

#define ASSERT(expr) \
    do { \
        if (!(expr)) {\
            assert_handler();\
        }\
    } while(0);

void assert_handler(void);

#endif
