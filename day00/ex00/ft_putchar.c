#include <unistd.h>

void ft_putchar(c)
{
    write(1,&c, 1);
}
