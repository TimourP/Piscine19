/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 10:03:15 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/14 09:57:05 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_baselen(char *base, int *count)
{
	int i;

	i = -1;
	while (base[++i])
		;
	*count = i;
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

void	ft_putnbr_base(int nbr, char *base)
{
	long	num;
	int		i;
	int		basecount;
	char	toprint[33];

	i = 0;
	num = nbr;
	if (test_error(base))
		return ;
	if (num < 0)
	{
		write(1, "-", 1);
		num = 0 - num;
	}
	ft_baselen(base, &basecount);
	while (num > 0)
	{
		toprint[30 - i] = base[num % basecount];
		num /= basecount;
		i++;
	}
	i = 31 - i - 1;
	while (toprint[++i])
		write(1, &toprint[i], 1);
}
