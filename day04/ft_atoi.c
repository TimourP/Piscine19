/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 23:08:29 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/12 23:51:52 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_charok(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (!(('0' <= str[i] && str[i] <= '9') || str[i] == '-' || str[i] == '+'))
		{
			return i;
		}
	}
	return i;
}

int		ft_atoi(char *str)
{
	int i;
	int num;
	int max;

	i = -1;
	max = ft_charok(str);
	while (++i < max)
	{

	}
	return 0;
}
