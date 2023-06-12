#include <string.h>

int strEndCheck(char *s, char *t)
{
    int s_size = strlen(s);
    int t_size = strlen(t);

    if (t_size > s_size)
    {
        return 0;
    }

    int diff = s_size - t_size;
    s += diff;

    while (*s != '\0')
    {
        if (*s != *t)
        {
            return 0;
        }
        s++;
        t++;
    }
    return 1;
}