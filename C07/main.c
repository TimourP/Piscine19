#include <stdio.h>

char	*ft_strjoin(int size, char **strs, char *sep);

int main(void)
{
    char *test[100] = {"hello", "je", "ma\0nge", "tout le\n\ntemps parce que c'est genial de manger"};
    char *testt = ft_strjoin(4, test, " ");
    int i;
    char c;

    i = -1;
    printf("%s\n", testt);
    while (testt[++i])
    {
        if (testt[i] <= 31)
            c = '.';
        else
            c = testt[i];
        printf("%i :\tasci : %i\tchar : %c\n", i, testt[i], c);
    }
        
    printf("%i :\tascii : %i\tchar : %c\n", i, testt[i], testt[i]);
    return 0;
}
