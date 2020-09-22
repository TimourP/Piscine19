#include <stdio.h>

char	**ft_split(char *str, char *charset);

int main(void)
{
    char test[100] = "hello comment vas tu";
    char wesplit[100] = " ";
    char **to = ft_split(test, wesplit);
    int i;
    int j;

    i = -1;
    while (to[++i])
    {
        j = -1;
        while (to[i][++j])
            printf("%i (%i) : \t char : %c \t ascii : %d\n", i, j, to[i][j], to[i][j]);
        printf("%i (%i) : \t char : %c \t ascii : %d\n", i, j, to[i][j], to[i][j]);
    }
    
    return 0;
}
