/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 08:05:36 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/12 11:50:00 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush_negatif(int *x, int *y)
{
	if (*x < 0)
		*x = 0 - *x;
	if (*y < 0)
		*y = 0 - *y;
}

void	rush(int x, int y)
{
	int i;
	int j;

	j = -1;
	if (x < 0 || y < 0)
		rush_negatif(&x, &y);
	while (++j < y)
	{
		i = -1;
		while (++i < x)
		{
			if (j == 0 || j == y - 1 || i == 0 || i == x - 1)
			{
				if ((i == 0 && j == 0) || (i == x - 1 && j == y - 1))
					write(1, "A", 1);
				else if ((i == x - 1 && j == 0) || (i == 0 && j == y - 1))
					write(1, "C", 1);
				else
					write(1, "B", 1);
			}
			else
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
}

int		main(void)
{
	rush(10000, 10000);
	return (0);
}
