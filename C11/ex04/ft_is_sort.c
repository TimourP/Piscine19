/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 07:44:55 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/21 08:42:56 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int comp1;
	int comp2;

	i = 1;
	while (i < length && !(comp1 = f(tab[i - 1], tab[i])))
		i++;
	while (i < length)
	{
		comp2 = f(tab[i - 1], tab[i]);
		if ((comp1 < 0 && comp2 > 0) || (comp1 > 0 && comp2 < 0))
			return (0);
		i++;
	}
	return (1);
}
