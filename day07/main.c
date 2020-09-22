#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max);

int main(void)
{
    int *test;
    int i;
    
    int tes = ft_ultimate_range(&test, -10, 10);
    i = -4;
    while (++i < 21)
    {
        printf("%i : %i\n", i, test[i]);
    }
    return 0;
}