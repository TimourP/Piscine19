#include <stdio.h>
#include <stdlib.h>

int			ft_atoi(char *str);

int main(void)
{
    char test[100] = " -123hello";
    int t2 = ft_atoi(test);
    int t3 = atoi(test);
    printf("%i\n", t2 == t3);
    return (0);
}

