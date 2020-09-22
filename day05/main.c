#include <stdio.h>

int		ft_sqrt(int nb);

int main(void)
{
    int i;

    i = -10;
    while (++i <= 100)
        printf("%d, %d\n", i, ft_sqrt(i));
    return (0);
}