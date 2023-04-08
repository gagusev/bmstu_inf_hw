#include "timer.h"

clock_t countdown_init(int countdown_secs) {
    clock_t start = clock_gettime() + (countdown_secs * CLOCKS_PER_SEC);
    return start;
}

countdown *countdown_update(clock_t start) {
    countdown *new = malloc(sizeof *new);

    clock_t time_now = clock_gettime();
    unsigned int mils = start - time_now;
    unsigned int secs = (mils / CLOCKS_PER_SEC) - (((mils / CLOCKS_PER_SEC)/60)*60);
    unsigned int mins = (mils / CLOCKS_PER_SEC) / 60;
    
    new->mils = mils; 
    new->secs = secs;
    new->mins = mins;

    return new;
}