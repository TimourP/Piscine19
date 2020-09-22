/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 21:45:10 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/15 16:56:05 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int i;

	i = 1;
	if (nb <= 1)
		return (0);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	while (++i <= nb / 5)
	{
		if (nb % i == 0)
			return (0);
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	int i;

	i = nb - 1;
	if (i < 1)
		i = 1;
	if (nb == 2147483647)
		return (0);
	while (++i)
	{
		if (ft_is_prime(i))
			return (i);
	}
	return (0);
}
