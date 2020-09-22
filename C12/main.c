#include "ft_list.h"
#include <stdio.h>

void	ft_list_push_front(t_list **begin_list, void *data);
int ft_list_size(t_list *begin_list);
void print_node(t_list *begin_list);
void    ft_list_push_back(t_list **begin_list, void *data);
t_list *ft_list_last(t_list *begin_list);
t_list *ft_list_push_strs(int size, char **strs);
t_list  *ft_list_at(t_list *begin_list, unsigned int nbr);
void ft_list_reverse(t_list **begin_list);

int main(void)
{
    t_list  *list = 0;
    char *tab[100] = {"jarvis", "hello", "helloa", "jemange"};
   
    list = ft_list_push_strs(3, tab);
    ft_list_reverse(&list);
    printf("------------------------------------------\n");
    print_node(list);
    printf("------------------------------------------\n");
    return (0);
}