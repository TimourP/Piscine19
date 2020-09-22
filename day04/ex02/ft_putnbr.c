/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 12:35:42 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/14 11:49:39 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putnbr(int nb)
{
	char	finalnb[12];
	long	newnb;
	int		i;

	i = 0;
	newnb = nb;
	if (newnb < 0)
	{
		newnb = -newnb;
		write(1, "-", 1);
	}
	while (newnb > 0)
	{
		finalnb[10 - i] = '0' + newnb % 10;
		newnb /= 10;
		i++;
	}
	write(1, finalnb, 12);
	printf("\n%d", finalnb[11] == '\0');
}
