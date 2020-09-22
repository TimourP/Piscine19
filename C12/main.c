#include "ft_list.h"
#include <stdio.h>

void print_node(t_list *begin_list);
t_list *ft_list_push_strs(int size, char **strs);
void ft_list_foreach(t_list *begin_list, void (*f)(void *));

void chante(void *data)
{
    printf("%s\n", data);
}

int main(void)
{
    t_list  *list = 0;
    char *tab[100] = {"jarvis", "hello", "helloa", "jemange"};
   
    list = ft_list_push_strs(4, tab);
    ft_list_foreach(list, &chante);
    printf("------------------------------------------\n");
    print_node(list);
    printf("------------------------------------------\n");
    return (0);
}