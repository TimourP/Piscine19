#include <stdio.h>

char	**ft_split(char *str, char *charset);

int main(void)
{
    char tosplit[1000] = "hello je me demande si les choses sont ainsi car on l'a defini ou bien car elles le sont implicitement";
    char cha[100] = "t";
    char **split = ft_split(tosplit, cha);
    int i;
    int j;

    i = -1;
    while (split[++i])
    {
        j = 0;
        while (split[i][++j])
            ;
        
        printf("%s \t%i\n", split[i], split[i][j] == 0);
    }
    return (0);
}