#ifndef DEBUG_H
#define DEBUG_H


enum debug_level {
    DEBUG = 0,
    INFO,
    WARN,
    ERROR,
};

void print_log(enum debug_level debug_lvl, char* log_msg);

#endif
