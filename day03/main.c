#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb);

int main(void)
{
    char d1[20] = "loup";
    char d2[20] = "loup";
    char s[20] = "";

    ft_strncat(d1, s, 2);
    strncat(d2, s, 2);
    printf("%s :::: %s\n", d1, d2);
}