/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 20:22:42 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/28 12:45:02 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_H
# define FT_LIB_H

# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct	s_grid_prop
{
	unsigned int height;
	unsigned int width;
	char empty;
	char notempty;
	char square;
}				t_grid_prop;

typedef struct	s_vec2u
{
	unsigned int x;
	unsigned int y;
}				t_vec2d;

void	ft_putnbr(int nb);
void	ft_putstr(char *str);
int		ft_atoi(char *str);
void    find_square(char *file_title);
void    write_bench(char *str, float t);

#endif