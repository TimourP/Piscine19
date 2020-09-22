/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 14:53:08 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/13 15:13:03 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	if (power <= 0)
		return 1;
	return nb * ft_recursive_power(nb, power - 1);
}
