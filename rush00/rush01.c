/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 15:50:03 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/12 16:59:29 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush_negatif(int *x, int *y)
{
	if (*x < 0)
		*x = 0 - *x;
	if (*y < 0)
		*y = 0 - *y;
}

void	ft_check_case(int x, int y, int i, int j)
{
	if ((i == 0 && j == 0) || (i == x - 1 && j == y - 1 && y > 1 && x > 1))
		ft_putchar('/');
	else if ((i == x - 1 && j == 0) || (i == 0 && j == y - 1))
		ft_putchar('\\');
	else
		ft_putchar('*');
}

void	rush(int x, int y)
{
	int i;
	int j;

	if (x == 0 || y == 0)
		return ;
	j = -1;
	rush_negatif(&x, &y);
	while (++j < y)
	{
		i = -1;
		while (++i < x)
		{
			if (j == 0 || j == y - 1 || i == 0 || i == x - 1)
			{
				ft_check_case(x, y, i, j);
			}
			else
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
