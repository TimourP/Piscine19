/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_not_print_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 08:31:51 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/22 10:08:18 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

void print_node(t_list *begin_list)
{
    t_list *tmp;

    tmp = begin_list;
    printf("Cette structure comporte < %i > elements et < %i > nodes\n", ft_list_size(begin_list), ft_list_size(begin_list) - 1);
	while (tmp)
    {
        if (tmp->next)
            printf("%s -> ", tmp->data);
        else
            printf("%s\n", tmp->data);
        tmp = tmp->next;
    }
}