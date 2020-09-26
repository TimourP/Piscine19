/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 03:54:53 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/26 05:21:25 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_H
# define FT_LIB_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h> 

typedef struct  s_num
{
    long nbr;
    char *text_nbr;
}               t_num;

void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
void    write_numbers(char *file_name, char *number);
void    write_billions(int nbr, char *file_name);
void    write_millions(int nbr, char *file_name);
void    write_thousands(int nbr, char *file_name);
void    write_units(int nbr, char *file_name);

#endif