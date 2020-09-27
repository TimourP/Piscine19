#include <stdio.h>

char *ft_convert_base(char *nbr, char *base_from, char *base_to);

int main(void)
{
    printf("%s", ft_convert_base("0", "0123456789", "01"));
    return 0;
}
