#include <stdio.h>

char	*ft_strjoin(int size, char **strs, char *sep);

int main(void)
{
    char *test[100] = {"test", "", "tess", "coucou"};
    char sep[100] = " ";
    char *join = ft_strjoin(4, test, sep);
    printf("%s\n", join);
    int i = -1;
    while (join[++i])
        printf("%d : %c (%d)\n", i, join[i], join[i]);
    printf("%d : %c (%d)\n", i, join[i], join[i]);
    return 0;
}