#include <stdio.h>
#include <string.h>

int		ft_strncmp(char *s1, char *s2, unsigned int n);

int main(void)
{
    char s1[20] = "\n";
    char s2[20] = "\n";

    printf("%d, %d\n", ft_strncmp(s1, s2, 10000), strncmp(s1, s2, 10000));
}