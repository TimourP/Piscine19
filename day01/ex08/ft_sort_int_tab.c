/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 11:53:10 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/10 18:45:52 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int min;
	int j;
	int curr;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size - i)
		{
			if (tab[i + j] < min || j == 0)
			{
				if (i != size)
				{
					min = tab[i + j];
					curr = j;
				}
			}
		}
		tab[i + curr] = tab[i];
		tab[i] = min;
	}
}
