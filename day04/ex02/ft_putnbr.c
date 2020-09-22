/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 12:35:42 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/14 17:04:48 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	toprint;
	long	newnb;

	newnb = nb;
	if (newnb < 0)
	{
		newnb = -newnb;
		write(1, "-", 1);
	}
	if (newnb > 9)
	{
		ft_putnbr(newnb / 10);
		toprint = '0' + newnb % 10;
		write(1, &toprint, 1);
	}
	else
	{
		toprint = '0' + newnb % 10;
		write(1, &toprint, 1);
	}
}
