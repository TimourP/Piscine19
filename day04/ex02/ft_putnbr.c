/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 12:35:42 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/13 09:49:44 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
		finalnb[11 - i] = '0' + newnb % 10;
		newnb /= 10;
		i++;
	}
	write(1, finalnb, 12);
}
