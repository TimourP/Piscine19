#include <stdio.h>

char	**ft_split(char *str, char *charset);

int main(void)
{
    char str[100] = "hello je dors bien";
    char chars[100] = " ";
    
    ft_split(str, chars);
    return 0;
}