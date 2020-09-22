/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:40:17 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/21 15:38:36 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_putnbr_base(int nbr, char *base);

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

int		check_inbase(char *base, char c)
{
	int i;

	i = -1;
	while (base[++i])
		if (base[i] == c)
			return (1);
	return (0);
}

int		test_error1(char *base, int *baselen)
{
	int i;
	int j;

	i = -1;
	while (base[++i])
		if (base[i] == '-' || base[i] == '+')
			return (1);
	if (i <= 1)
		return (1);
	i = -1;
	while (base[++i])
	{
		j = i;
		while (base[j++])
		{
			if (base[j] == base[i] && i != j)
				return (1);
		}
	}
	i = -1;
	while (base[++i])
		;
	*baselen = 0;
	*baselen = i;
	return (0);
}

int		calculate_to_add(char *base, int baselen, char c, int puiss)
{
	int index;
	int i;
	int value;

	i = -1;
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
		value *= baselen;
	}
	return (value * index);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int				num;
	int				neg;
	int				baselen;
	int				max;

	neg = 0;
	num = 0;
	max = 0;
	if (test_error1(base_from, &baselen) || test_error1(base_to, &baselen))
		return (NULL);
	while ((*nbr >= 9 && *nbr <= 13) || *nbr == ' ')
		nbr++;
	while (*nbr == '+' || *nbr == '-')
	{
		neg = (*nbr == '-') ? !neg : neg;
		nbr++;
	}
	while (check_inbase(base_from, nbr[++max]))
		;
	while (check_inbase(base_from, *nbr))
	{
		num += calculate_to_add(base_from, baselen, *nbr, --max);
		nbr++;
	}
	return (ft_putnbr_base((neg ? -num : num), base_to));
}
