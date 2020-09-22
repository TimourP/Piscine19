#include <stdio.h>
#include <stdlib.h>

int			ft_atoi_base(char *str, char *base);

int main(void)
{
    char test[100] = "-123";
    char base[100] = "0123456789";
    int test1 = ft_atoi_base(test, base);

    printf("%d\n", test1);
    return (0);
}
