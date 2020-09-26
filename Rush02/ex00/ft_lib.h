/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 03:54:53 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/26 18:07:28 by tpetit           ###   ########.fr       */
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
char			*find_in_dict(t_num **dict, char *str);
void			write_suffix(unsigned int count, t_num **dict, int index, char *num);
int				test_if_end(int i, char *num);
int				is_space(char c);
void			ft_puttextnumber(char *str);
void			free_all(t_num **dict);
int				check_in_dict(t_num **dict, char *str);
int 			check_suffix(unsigned int count, t_num **dict, int index, char *num);
int				check_result(t_num **dict, char *nbr);

#endif
