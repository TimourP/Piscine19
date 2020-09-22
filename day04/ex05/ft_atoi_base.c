/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 11:55:58 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/13 13:54:37 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		test_base(char c, char *base)
{
	int i;

	i = -1;
	while (base[++i])
	{
		if (base[i] == c)
			return (0);
	}
	return (1);
}

void	ft_charok(char *str, char *base, int min, int *max)
{
	int i;

	i = min - 1;
	while (str[++i])
	{
		if (test_base(str[i], base))
		{
			*max = i;
			return ;
		}
	}
	*max = i;
}

int		calculate_to_add(int nbr, int puiss, char *base, char c)
{
	int		i;
	int		index;
	int		value;

	i = -1;
	index = 0;
	while (base[++i])
	{
		if (base[i] == c)
		{
			index = i;
			break ;
		}
	}
	i = -1;
	value = 1;
	while (++i < puiss)
	{
		value *= nbr;
	}
	return (value * index);
}

void	set_lenmax(char *str, char *base, int *baselen, int *minmaxne)
{
	int i;

	i = -1;
	minmaxne[2] = 0;
	*minmaxne = 0;
	*baselen = 0;
	while (base[++i])
		*baselen = *baselen + 1;
	if (str[0] == '-')
	{
		minmaxne[2] = 1;
		*minmaxne = 1;
	}
	else if (str[0] == '+')
		*minmaxne = 1;
}

int		ft_atoi_base(char *str, char *base)
{
	int		i;
	long	num;
	int		minmax[3];
	int		baselen;

	num = 0;
	set_lenmax(str, base, &baselen, minmax);
	ft_charok(str, base, minmax[0], &minmax[1]);
	i = minmax[0] - 1;
	while (++i < minmax[1])
	{
		num += calculate_to_add(baselen, minmax[1] - i - 1, base, str[i]);
	}
	if (minmax[2])
		num = -num;
	return (num);
}
