#include <stdio.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int main(void)
{
    char num[100] = "00001";
    char b1[100] = "01";
    char b2[100] = "01";
    
    char *test = ft_convert_base(num, b1, b2);

    printf("%s\n", test);
    return 0;
}