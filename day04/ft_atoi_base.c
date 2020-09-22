/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 11:55:58 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/13 13:19:54 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 23:08:29 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/13 09:45:03 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int         test_base(char c, char *base)
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

void		ft_charok(char *str, char *base, int min, int *max)
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

int findindex(char *base, char c)
{
    int i;

    i = -1;
    while (base[++i])
    {
        if (base[i] == c)
            return (i);
    }
    return (0);
}

int expo(int nbr, int puiss)
{
    int i;
    int value;

    i = -1;
    value = 1;
    while (++i < puiss)
    {
        value *= nbr;
    }
    return (value);
}

int			ft_atoi_base(char *str, char *base)
{
	int		i;
	long	num;
	int		neg;
	int		min;
	int		max;
    int     baselen;

	num = 0;
    min = 0;
    max = 0;
	neg = 0;
    baselen = 0;
    i = -1;
    while (base[++i])
        baselen ++;
    if (str[0] == '-')
    {
        neg = 1;
        min = 1;
    }
    else if(str[0] == '+')
        min = 1;
	ft_charok(str, base, min, &max);
	i = min - 1;
	while (++i < max)
	{
        num += (findindex(base, str[i]) * expo(baselen, max - i - 1));
	}
	if (neg)
		num = -num;
	return (num);
}
