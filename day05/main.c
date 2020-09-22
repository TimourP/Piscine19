#include <stdio.h>

int		ft_find_next_prime(int nb);

int main(void)
{
    int test = ft_find_next_prime(2147483641);
    printf("%d\n", test);
}