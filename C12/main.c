#include "ft_list.h"
#include <stdio.h>

void	ft_list_push_front(t_list **begin_list, void *data);
int ft_list_size(t_list *begin_list);
t_list *ft_list_last(t_list *begin_list);

int main(void)
{
    t_list  *list;
    ft_list_push_front(&list, "hello");
    ft_list_push_front(&list, "tom");
    ft_list_push_front(&list, "liza");
    printf("%s\n", list -> next -> next -> data);
    //printf("last one : %s\n", ft_list_last(list) -> data);
    printf("%i\n", ft_list_size(list));
    return (0);
}