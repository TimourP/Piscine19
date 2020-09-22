
#include <unistd.h>
#include <stdio.h>

void ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *));

int changenum(int nb, int nb2)
{
    return (nb - nb2);
}



int main(void)
{
    char *tab[6] = {"hello", "allo", "test", "hallo", "123", "l"};
    tab[5] = NULL;
    int i;
    ft_advanced_sort_string_tab(tab, &ft_strcmp);
    i = -1;
    while(tab[++i])
        printf("%s\n", tab[i]);
}