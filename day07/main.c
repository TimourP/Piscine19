#include <stdio.h>

char	**ft_split(char *str, char *charset);

int main(void)
{
    char str[100] = "hello je dors bien comment peut on faire ca";
    char chars[100] = " ";
    
    char **test = ft_split(str, chars);
    return 0;
}