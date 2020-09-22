/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 11:55:58 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/15 09:59:09 by tpetit           ###   ########.fr       */
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

int			ft_atoi_base(char *str, char *base)
{
	int	num;
	int	neg;

	neg = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = !neg;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = 10 * num + ('0' - *str);
		str++;
	}
	if (neg)
		num = -num;
	return (num);
}
