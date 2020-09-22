/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 11:53:10 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/09 20:46:28 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int min;
	int j;
	int transit;

	i = -1;
	while (i++ < size - 1)
	{
		j = -1;
		while (j++ < size - i - 1)
		{
			if (tab[j + i] < min || j == 0)
			{
				min = tab[j + i];
				tab[j + i] = tab[i];
				tab[i] = min;
			}
		}
	}
}
