/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 03:54:53 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/26 04:17:45 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_H
# define FT_LIB_H

#include <stdio.h>

void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
void    write_numbers(char *file_name, char *number);

#endif