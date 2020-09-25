/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 08:22:34 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/25 08:47:53 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_putnbr_base(int nbr, char *base);

int		check_inbase(char *base, char c)
{
	int i;

	i = -1;
	while (base[++i])
		if (base[i] == c)
			return (1);
	return (0);
}

int		test_error(char *base)
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
	return (0);
}

int ft_strlen(char *str)
{
    int i;

    i = -1;
    while (str[++i])
        ;
    return (i);
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

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    int num;
    int negatif;
    int numlen;

    negatif = 0;
	num = 0;
	numlen = 0;
    if (test_error(base_from) || test_error(base_to))
		return (0);
    while ((*nbr >= 9 && *nbr <= 13) || *nbr == ' ')
		nbr++;
	while (*nbr == '+' || *nbr == '-')
	{
		negatif = (*nbr == '-') ? !negatif : negatif;
		nbr++;
	}
    while (check_inbase(base_from, nbr[++numlen]))
		;
    while (check_inbase(base_from, *nbr))
	{
		num += calculate_to_add(base_from, ft_strlen(base_from), *nbr, --numlen);
		nbr++;
	}
    return (ft_putnbr_base(negatif ? -num : num, base_to));
}