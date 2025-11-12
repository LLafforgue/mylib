#include "printf.h"

size_t  ft_strlen(const char *s)
{
    const char *temp;

    temp = s;
    while (*s)
        s++;
    return (s - temp);
}