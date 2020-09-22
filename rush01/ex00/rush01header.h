/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01header.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 13:34:40 by mlefevre          #+#    #+#             */
/*   Updated: 2020/09/19 13:34:45 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01HEADER_H
# define RUSH01HEADER_H

int		respect_borders(int *grid, int *borders);
int		can_put_nbr(int index, int nbr);
void	put_nbr_in_grid(int index, int nbr);
void	print_solution(void);
int		search(int index, int *borders);

#endif
