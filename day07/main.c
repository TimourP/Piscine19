#include <stdio.h>

char *ft_convert_base(char *nbr, char *base_from, char *base_to);

int main(void)
{
    char nbr[100] = "1234";
    char base1[100] = "0123456789";
    char base2[100] = "0123456789";
    char *c;
    
    c = ft_convert_base(nbr, base1, base2);
    printf("%s", c);
}