#include <stdio.h>
#include "ft_swap.c"

int main ()
{
    int a = 10;
    int b = 20;
    ft_swap(&a, &b);
    printf("%d, %d", a, b);
    return 0;
}