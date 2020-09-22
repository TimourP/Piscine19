/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 14:49:30 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/15 12:29:01 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int i;
	int value;

	value = 1;
	i = -1;
	if (power < 0)
		return (0);
	while (++i < power)
	{
		value *= nb;
	}
	return (value);
}
