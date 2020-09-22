#include <stdio.h>

char	**ft_split(char *str, char *charset);

int main(void)
{
    char str[100] = "hello je dors bien comment peut on faire ca";
    char chars[100] = " ";
    
    char **test = ft_split(str, chars);
    int i;
    int count;
    int j;

    i = -1;
    while (test[++i])
    {
        j = -1;
        count = 0;
        while (test[i][++j])
        {
            count++;
        }
        printf("%s --> %d\n", test[i], test[i][count] == 0);
    }
    return 0;
}