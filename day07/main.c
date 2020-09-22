#include <stdio.h>

char *ft_strjoin(int size, char **strs, char *sep);

int main(void)
{
    char *test[100] = {"hello", "comment", "tu", "vas"};
    char sep[100] = " _ ";
    int i;
    
    char *teste = ft_strjoin(4, test, sep);
    printf("%s\n", teste);
    i = -1;
    while (teste[++i])
    {
        printf("%d : %c\n", i, teste[i]);
    }
    printf("%d : %d\n", i, teste[i] == 0);
    return 0;
}