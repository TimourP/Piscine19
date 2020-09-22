
#include <unistd.h>
#include <stdio.h>

int ft_is_sort(int *tab, int length, int(*f)(int, int));

int changenum(int nb, int nb2)
{
    return (nb - nb2);
}

int main(void)
{
    int tab[5] = {1, 2, 2, 3, 4};
    int tab2 = ft_is_sort(tab, 5, &changenum);
    printf("%d\n", tab2);
}