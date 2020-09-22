/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 10:03:15 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/13 10:46:43 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_baselen(char *base, int *count)
{
	int i;

	i = -1;
	while (base[++i])
		;
	*count = i;
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	num;
	int		i;
	int		basecount;
	char	toprint[33];

	i = 0;
	num = nbr;
	if (num < 0)
	{
		write(1, "-", 1);
		num = 0 - num;
	}
	ft_baselen(base, &basecount);
	while (num > 0)
	{
		toprint[31 - i] = base[num % basecount];
		num /= basecount;
		i++;
	}
	i = 32 - i - 1;
	while (toprint[++i])
		write(1, &toprint[i], 1);
}
