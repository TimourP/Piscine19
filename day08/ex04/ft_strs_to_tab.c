/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 12:03:29 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/20 09:16:51 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>
#include <stdio.h>

int					ft_strlen(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

char				*ft_strdup(char *str)
{
	int		i;
	char	*dest;

	if (!(dest = malloc(ft_strlen(str) * sizeof(char))))
		return (NULL);
	i = -1;
	while (str[++i])
		dest[i] = str[i];
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	t_stock_str			*t_stock;

	i = -1;
	if (ac < 0)
		ac = 0;
	if (!(t_stock = malloc(sizeof(t_stock_str) * (ac + 1))))
		return (NULL);
	while (++i < ac)
	{
		t_stock[i].size = ft_strlen(av[i]);
		t_stock[i].str = av[i];
		t_stock[i].copy = ft_strdup(av[i]);
	}
	t_stock[i].str = 0;
	return (t_stock);
}
