#pragma once

int count_odd_bits(int num)
{
    int sum = 0;
    for (int k = 0; k < 32; k += 2)
    {
        int mask = 1 << k;
        int masked_n = num & mask;
        int thebit = masked_n >> k;
        sum += thebit;
    }
    return sum;
}