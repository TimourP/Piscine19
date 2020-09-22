#include <stdio.h>
#include <stdlib.h>

void	ft_putnbr_base(int nbr, char *base);

int main(void)
{
    int test = -0;
    char base[100] = "678";
    ft_putnbr_base(test, base);
    return (0);
}
