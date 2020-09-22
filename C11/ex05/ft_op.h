/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 08:00:28 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/21 08:51:53 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

void	ft_add(int nb1, int nb2);
void	ft_sub(int nb1, int nb2);
void	ft_mul(int nb1, int nb2);
void	ft_div(int nb1, int nb2);
void	ft_mod(int nb1, int nb2);
int		ft_atoi(char *str);
void	ft_solve_eq(char *num1, char *operation, char *num2);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);

#endif