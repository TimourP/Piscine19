/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 03:54:53 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/26 12:53:34 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_H
# define FT_LIB_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_num
{
	char *nbr;
	char *text_nbr;
}				t_num;

void			ft_putstr(char *str);
unsigned int	ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
void			write_numbers(char *file_name, char *number);
int				check_num(char *str);
void			print_result(t_num **dict, char *nbr);

#endif
