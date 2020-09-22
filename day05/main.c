#include <stdio.h>

int		ft_is_prime(int nb);

int main(void)
{
    int nbr = 2147483647;
    int val = ft_is_prime(nbr);

    printf("%d\n", val);
}