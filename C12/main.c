#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>
void print_node(t_list *begin_list);
t_list *ft_list_push_strs(int size, char **strs);
void	ft_list_remove_if(t_list **begin_list, void *data_ref,
		int (*cmp)(), void(*free_fct)(void *));
int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	if (s1[i] != '\0')
		return (s1[i]);
	else if (s2[i] != '\0')
		return (0 - s2[i]);
	return (0);
}

void freef(void *data)
{
    printf("%s\n", data);
}

int main(void)
{
    t_list  *list = 0;
    char *tab[100] = {"jarvis"};
   
    list = ft_list_push_strs(5, tab);
    ft_list_remove_if(&list, "jarvis", &ft_strcmp, &freef);
    printf("------------------------------------------\n");
    //print_node(list);
    printf("------------------------------------------\n");
    return (0);
}