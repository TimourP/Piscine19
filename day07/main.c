#include <stdio.h>

int     *ft_ultimate_range(int **range, int min, int max);

int main(void)
{
    int *tab;
    int min = -10;
    int max = 10;
    int test;

    test = -1;
    ft_ultimate_range(&tab, min, max);
    while (++test < max - min)
    {
        printf("%d\n", *tab);
        tab ++;
    }
}