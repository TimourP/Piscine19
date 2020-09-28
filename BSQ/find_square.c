/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 22:01:39 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/28 16:32:39 by tpetit           ###   ########.fr       */
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
	close(filedesc);
	return (1);
}

int count_colums(t_grid_prop *grid, char *file_title)
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
	unsigned int index;
	char	*buff;
	int		filedesc;
	int		bufflen;
	int		first;
	int max;
	int index_of_max;
	int i;

	index = 0;
	i = -1;
	index_of_max = 0;
	buff = malloc(sizeof(char) * (grid_info->width + 1));
	max = 0;
	first = 1;
	if ((filedesc = open(file_title, O_RDONLY)) == -1)
		return 0;
	read(filedesc, buff, grid_info->first_ligne_len);
	while ((bufflen = read(filedesc, buff, grid_info->width + 1)) > 0)
	{
		i = -1;
		while (++i < bufflen && buff[i] != '\n')
		{
			if (buff[i] == grid_info->notempty)
				grid[index] = 0;
			else if (index < grid_info->width)
				grid[index] = 1;
			else if (i == 0)
				grid[index] = 1;
			else
			{
				if ((grid[index] = get_min(grid, grid_info, index) + 1) > max)
				{
					max = grid[index];
					index_of_max = index;
				}
			}
			index++;
		}
	}
	if (index != grid_info->width * grid_info->height)
		return (-1);
	close(filedesc);
	return (index_of_max);
}

void print_result(int *grid, t_grid_prop grid_info, int index)
{
	t_vec2u pos = c_vec2u(-1, -1);
	const t_vec2u posind = c_vec2u(index % grid_info.width, index / grid_info.width);
	const int max_value = grid[index];
	char *toprint;

	toprint = malloc(sizeof(char) * grid_info.width);
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
}

void find_square(char *file_title)
{
	t_grid_prop grid_info;
	int			*main_grid;
	int index;

	index = 0;
	if (!read_first_line(&grid_info, file_title))
		return ;
	if (!count_colums(&grid_info, file_title))
		return ;
	if (!(main_grid = malloc(sizeof(int) * (grid_info.width * grid_info.height))))
		return (ft_puterr("Malloc error\n"));
	if ((index = fill_up_grid(main_grid, &grid_info, file_title)) < 0)
		return (ft_puterr("map error\n"));
	//ft_putnbr(index % grid_info.width);
	//ft_putstr("  ");
	//ft_putnbr(index / grid_info.width);
	//ft_putstr("\n");
	print_result(main_grid, grid_info, (unsigned int)index);
}