#include <unistd.h>

void ft_putstr(char * str)
{
    int i;
    i = -1;
    while(str[i++] != '\0')
    {
        write(1, &str[i], 1);
    }
}