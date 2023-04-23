#include "timer.h"

int countdown_init(int countdown_secs) {
    int start = (int)time(NULL) + countdown_secs;
    return start;
}

countdown *countdown_update(int start) {
    countdown *new = malloc(sizeof *new);

    int time_now = (int)time(NULL);
    
    unsigned int mins = (start - time_now)/60;
    unsigned int secs = start - time_now - mins * 60;
    
    new->secs = secs;
    new->mins = mins;

    return new;
}