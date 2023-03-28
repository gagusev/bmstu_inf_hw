#include <time.h>

typedef struct {
    unsigned int mins;
    unsigned int secs;
    unsigned int mils;
} countdown;

clock_t countdown_init(int countdown_secs);
countdown *countdown_update(clock_t start);