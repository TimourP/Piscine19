/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queen_puzzle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 22:09:40 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/13 22:42:22 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


void	init_grid(int *grid, int start, int first, int *count)
{
	int i;

	i = start - 1;
	while (++i < 10)
		grid[i] = -1;
	if (first)
	{
		grid[0] = 0;
		*count = 0;
	}
}

int		abs(int num)
{
	if (num < 0)
		return (0 - num);
	return (num);
}

int		check_poss(int *grid, int line, int height)
{
	int i;
	int q;
	int c;

	i = -1;
	q = height + line * 10;
	while (++i < line)
	{
		if (grid[i] != -1)
		{
			c = grid[i] + 10 * i;
			if (q % 10 == grid[i])
				return (0);
			if (abs(q - c) % (10 + 1) == 0 && abs(q - c) > abs(line - i) * 10)
				return (0);
			if (abs(q - c) % (10 - 1) == 0 && abs(q - c) < abs(line - i) * 10)
				return (0);
		}
	}
	return (1);
}

int		check_line(int *grid, int line)
{
	int i;

	i = grid[line];
	while (++i < 10)
	{
		if (check_poss(grid, line, i))
			return (i);
	}
	return (-2);
}

int		ft_ten_queen_puzzle(void)
{
	int	grid[10];
	int count;
	int nextline;
	int i;

	init_grid(grid, 0, 1, &count);
	while (grid[0] != -1)
	{
		nextline = check_line(grid, count);
		if(nextline != -2)
        {
            grid[count] = nextline;
            count ++;
        }else
        {
            init_grid(grid, count, 0, 0);
            if(count > 0)
                count--;
        }
        if (count == 10)
        {
			i = -1;
            while (++i < 10)
				printf("%d", grid[i]);
			printf("\n");
        }  
	}
	return (0);
}
