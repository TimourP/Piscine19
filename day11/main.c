
#include <unistd.h>
#include <stdio.h>

void	ft_sort_string_tab(char **tab);

int changenum(int nb, int nb2)
{
    return (nb - nb2);
}

int main(void)
{
    char *tab[5] = {"hello", "allo", "\n"};
    ft_sort_string_tab(tab);

    printf("%s\n", tab[0]);
}