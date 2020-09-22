#include <stdio.h>
#include"ft_sort_int_tab.c"

int main ()
{
    int test[4] = {17, 2, 3, 4};
    ft_sort_int_tab(test, 4);
    printf("%d, %d, %d, %d", test[0], test[1], test[2], test[3]);

}