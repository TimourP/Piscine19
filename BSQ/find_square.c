/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 22:01:39 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/29 08:44:44 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

int	read_first_line(t_grid_prop *grid, char *file_title)
{
	char	buff[128];
	int		filedesc;
	int		bufflen;
	int		i;

	i = -1;
	grid->first_ligne_len = 0;
	if ((filedesc = open(file_title, O_RDONLY)) == -1)
		return (0);
	if ((bufflen = read(filedesc, buff, 128)) > 0)
	{
		grid->height = ft_atoi(buff);
		while (buff[++i] >= '0' && buff[i] <= '9')
			grid->first_ligne_len++;
		grid->empty = buff[i];
		grid->notempty = buff[i + 1];
		grid->square = buff[i + 2];
	}
	grid->first_ligne_len += 4;
	if (close(filedesc) == -1 || bufflen == -1)
		return (0);
	return (1);
}

int count_columns(t_grid_prop *grid, char *file_title)
{
	char			buff[1];
	int				filedesc;
	int				bufflen;
	unsigned int	count;
	int				first;

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
	grid->width = count;
	if (close(filedesc) == -1 || bufflen == -1)
		return (0);
	return (1);
}

int get_min(int *grid, const t_grid_prop *grid_info, int index)
{
	const int nb1 = grid[index - 1];
	const int nb2 = grid[index - grid_info->width];
	const int nb3 = grid[index - grid_info->width - 1];

	if (nb1 <= nb2 && nb1 <= nb3)
    	return (nb1);
	else if (nb2 <= nb3 && nb2 <= nb1)
    	return (nb2);
	else 
    	return (nb3);
}

int fill_up_grid(int *grid, const t_grid_prop *grid_info, char *file_title)
{
	t_fill_up_grid loc;

	loc.index = 0;
	loc.i = -1;
	loc.index_of_max = 0;
	loc.max = 0;
	loc.first = 1;
	if ((loc.filedesc = open(file_title, O_RDONLY)) == -1)
		return (0);
	if (!(loc.buff = malloc(sizeof(char) * (grid_info->width + 1))))
		return (-1);
	read(loc.filedesc, loc.buff, grid_info->first_ligne_len);
	while ((loc.bufflen = read(loc.filedesc, loc.buff, grid_info->width + 1)) > 0)
	{
		loc.i = -1;
		while (++loc.i < loc.bufflen && loc.buff[loc.i] != '\n')
		{
			if (loc.buff[loc.i] == grid_info->notempty)
				grid[loc.index] = 0;
			else if (loc.index < grid_info->width)
			{
				grid[loc.index] = 1;
				if (grid[loc.index] > loc.max)
				{
					loc.max = grid[loc.index];
					loc.index_of_max = loc.index;
				}
			}
			else if (loc.i == 0)
			{
				grid[loc.index] = 1;
				if (grid[loc.index] > loc.max)
				{
					loc.max = grid[loc.index];
					loc.index_of_max = loc.index;
				}
			}
			else if ((grid[loc.index] = get_min(grid, grid_info, loc.index) + 1) > loc.max)
				{
					loc.max = grid[loc.index];
					loc.index_of_max = loc.index;
				}
			loc.index++;
		}
	}
	free(loc.buff);
	if (close(loc.filedesc) == -1 || loc.bufflen == -1
	|| loc.index != grid_info->width * grid_info->height)
		return (0);
	return (loc.index_of_max);
}

void print_result(int *grid, t_grid_prop grid_info, int index)
{
	t_vec2u pos = c_vec2u(-1, -1);
	const t_vec2u posind = c_vec2u(index % grid_info.width, index / grid_info.width);
	const int max_value = grid[index];
	char *toprint;

	if (!(toprint = malloc(sizeof(char) * grid_info.width)))
	{
		free(grid);
		return (ft_puterr("Malloc error\n"));
	}
	while (++pos.y < grid_info.height)
	{
		pos.x = -1;
		while (++pos.x < grid_info.width)
		{
			if (grid[pos.y * grid_info.width + pos.x] == 0)
				toprint[pos.x] = grid_info.notempty;
			else if (pos.x >= posind.x - max_value + 1 && pos.x <= posind.x
				&& pos.y >= posind.y - max_value + 1 && pos.y <= posind.y)
				toprint[pos.x] = grid_info.square;
			else
				toprint[pos.x] = grid_info.empty;
		}
		write(1, toprint, grid_info.width);
		ft_putstr("\n");
	}
	free(grid);
	free(toprint);
}

void find_square(char *file_title)
{
	t_grid_prop	grid_info;
	int			*main_grid;
	int			index;

	if (!read_first_line(&grid_info, file_title))
		return (ft_puterr("map error\n"));
	if (!count_columns(&grid_info, file_title))
		return (ft_puterr("map error\n"));
	if (!(main_grid = malloc(sizeof(int) * (grid_info.width * grid_info.height))))
		return (ft_puterr("Malloc error\n"));
	if ((index = fill_up_grid(main_grid, &grid_info, file_title)) < 0)
	{
		free(main_grid);
		if (index == 0)
			return (ft_puterr("map error\n"));
		else
			return (ft_puterr("Malloc error\n"));
	}
	print_result(main_grid, grid_info, index);
}
