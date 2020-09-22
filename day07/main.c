#include <stdio.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
char	*ft_2convert_base(char *nbr, char *base_from, char *base_to);

int main(void)
{
    char num[100] = "2147483F7";
    char base1[100] = "-03";
    char base2[100] = "01";
    char *numtobase2 = ft_convert_base(num, base1, base2);
    char *numtobase22 = ft_convert_base(num, base1, base2);
    printf("%s\n", numtobase2);
    printf("%s\n", numtobase22);
    return 0;
}