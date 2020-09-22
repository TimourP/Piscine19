#include <stdio.h>
#include <string.h>

int		ft_strncmp(char *s1, char *s2, unsigned int n);

int main(void)
{
    char s1[20] = "\n";
    char s2[20] = "\n";
    int nb = 19;
    
    printf("%d, %d", ft_strncmp(s1, s2, nb), strncmp(s1, s2, nb));
}