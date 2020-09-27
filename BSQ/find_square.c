/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 22:01:39 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/28 00:37:50 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

typedef struct	s_grid_prop
{
	int height;
	int width;
	char empty;
	char notempty;
	char square;
}				t_grid_prop;

int	read_first_line(t_grid_prop *grid, char *file_title)
{
	char	buff[128];
	int		filedesc;
	int		bufflen;
	int		i;

	i = -1;
	if ((filedesc = open(file_title, O_RDONLY)) == -1)
		return (0);
	if ((bufflen = read(filedesc, buff, 128)) > 0)
	{
		grid->height = ft_atoi(buff);
		while (buff[++i] >= '0' && buff[i] <= '9')
			;
		grid->empty = buff[i];
		grid->notempty = buff[i + 1];
		grid->square = buff[i + 2];
	}
	close(filedesc);
	return (1);
}

int count_lines(t_grid_prop *grid, char *file_title)
{
	char	buff[1];
	int		filedesc;
	int		bufflen;
	int		count;
	int		first;

	count = 0;
	first = 1;
	if ((filedesc = open(file_title, O_RDONLY)) == -1)
		return (0);
	while ((bufflen = read(filedesc, buff, 1)) > 0)
	{
		if (buff[0] == '\n' && !first)
			break ;
		else if (buff[0] == '\n')
			first = 0;
		else if (!first)
			count++;
	}
	close(filedesc);
	grid->width = count;
	return (1);
}

void init_grid(int *grid, int size)
{
	int i;

	i = -1;
	while (++i < size)
		grid[i] = -1;
}

void print_grid(int *grid, int width, int height)
{
	int i;
	int j;

	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
		{
			if (grid[i * width + j] == -1)
				ft_putstr(" ");
			else
				ft_putnbr(grid[i * width + j]);
			ft_putstr(" ");
		}
		ft_putstr("\n");
	}
}

int get_min(int *grid, t_grid_prop grid_info, int index)
{
	if (grid[1] < grid[2] && grid [1] < grid[3])
		return (grid[1]);
	if (grid[2] < grid[1] && grid [2] < grid[3])
		return (grid[2]);
	if (grid[3] < grid[2] && grid [3] < grid[1])
		return (grid[3]);
}

void fill_up_grid(int *grid, t_grid_prop grid_info, char *file_title)
{
	int index;
	char	buff[1];
	int		filedesc;
	int		bufflen;
	int		first;

	(void)grid_info;
	(void)grid;
	index = 0;
	first = 1;
	if ((filedesc = open(file_title, O_RDONLY)) == -1)
		return ;
	while ((bufflen = read(filedesc, buff, 1)) > 0)
	{
		if (buff[0] != '\n' && first)
			;
		else if (buff[0] == '\n')
			first = 0;
		else if (!first)
		{
			if (buff[0] == grid_info.notempty)
				grid[index] = 0;
			else if (index < grid_info.width)
				grid[index] = 1;
			else if (!(index%grid_info.width))
				grid[index] = 1;
			else
				grid[index] = get_min(grid, grid_info, index);
			index++;
		}
	}
	close(filedesc);
	return ;
}

void find_square(char *file_title)
{
	t_grid_prop grid_info;
	int			*main_grid;

	if (!read_first_line(&grid_info, file_title))
		return ;
	if (!count_lines(&grid_info, file_title))
		return ;
	if (!(main_grid = malloc(sizeof(int) * (grid_info.width * grid_info.height))))
		return ;
	init_grid(main_grid, grid_info.width * grid_info.height);
	fill_up_grid(main_grid, grid_info, file_title);
	print_grid(main_grid, grid_info.width, grid_info.height);
}