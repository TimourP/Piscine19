/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 11:23:25 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/22 13:42:25 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size3(t_list *begin_list)
{
	if (begin_list)
		return (1 + ft_list_size(begin_list -> next));
	else
		return (0);
}

t_list  *ft_list_at2(t_list *begin_list, unsigned int nbr)
{
	t_list *tmp;
	unsigned int size;
	unsigned int count;

	size = ft_list_size3(begin_list);
	if (size <= nbr)
	{
		tmp = 0;
		return (tmp);
	}
	tmp = begin_list;
	count = -1;
	while (tmp)
	{
		count++;
		if (count == nbr)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

void ft_list_reverse(t_list **begin_list)
{
	int size;
	int i;

	i = -1;
	size = ft_list_size3(*begin_list);
	while (++i < size - 2)
	{
		ft_list_at2(*begin_list, size - i)->next = ft_list_at2(*begin_list, size - i - 1);
	}
	
}