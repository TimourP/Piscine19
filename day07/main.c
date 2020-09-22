#include <stdio.h>

char *ft_strjoin(int size, char **strs, char *sep);

int main(void)
{
    char *strr[10] = {"bonjouree", "commenttttt", "vas tu?"};
    char step[10] = "|hello|";
    char *dest = ft_strjoin(3, strr, step);
    printf("%s\n", dest);
}