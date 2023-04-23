#include <time.h>
#include <stdlib.h>

typedef struct {
    unsigned int mins;
    unsigned int secs;
} countdown;

int countdown_init(int countdown_secs);
countdown *countdown_update(int start);