/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ope.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 08:13:15 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/21 08:18:35 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_op.h"

void	ft_add(int nb1, int nb2)
{
	ft_putnbr(nb1 + nb2);
	ft_putstr("\n");
}

void	ft_sub(int nb1, int nb2)
{
	ft_putnbr(nb1 - nb2);
	ft_putstr("\n");
}

void	ft_mul(int nb1, int nb2)
{
	ft_putnbr(nb1 * nb2);
	ft_putstr("\n");
}

void	ft_div(int nb1, int nb2)
{
	if (nb2)
		ft_putnbr(nb1 / nb2);
	else
		ft_putstr("Stop : division by zero");
	ft_putstr("\n");
}

void	ft_mod(int nb1, int nb2)
{
	if (nb2)
		ft_putnbr(nb1 % nb2);
	else
		ft_putstr("Stop : modulo by zero");
	ft_putstr("\n");
}
