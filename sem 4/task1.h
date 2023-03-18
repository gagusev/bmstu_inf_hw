#pragma once

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int hexstr_to_decint(char str[], int strlen)
{
    int sum = 0;
    int power = strlen - 1;

    for (int i = 0; i < strlen; ++i)
    {
        char c = str[i];
        if (c >= '0' && c <= '9')
        {
            sum += pow(16, power) * (c - '0');
        }
        else if (c >= 'a' && c <= 'f')
        {
            sum += pow(16, power) * (c - 'a' + 10);
        }
        else if (c >= 'A' && c <= 'F')
        {
            sum += pow(16, power) * (c - 'A' + 10);
        }
        else
        {
            puts("\nERROR: Only hex-symbols are allowed\n");
            exit(1);
        }
        power--;
    }

    return sum;
}