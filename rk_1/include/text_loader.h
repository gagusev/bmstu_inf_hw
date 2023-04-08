#include <string.h>
#include <stdio.h>
#include <sys/types.h>

#define MAX_LINES 128
#define MAX_WIDTH 400

int text_to_lines(const char path_to_file[], int max_x, char out[MAX_LINES][MAX_WIDTH]);