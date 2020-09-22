#include <stdio.h>

char	**ft_split(char *str, char *charset);
char	*ft_strjoin(int size, char **strs, char *sep);

int main(void)
{
    char *test[100] = {};
    char *testt = ft_strjoin(0, test, " ");
    printf("%s\n", testt);
    
    return 0;
}
