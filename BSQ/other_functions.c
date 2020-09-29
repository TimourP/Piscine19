/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 09:59:52 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/29 10:23:18 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

int	test_char_in_grid(const t_grid_prop *grid)
{
	if (grid->empty == grid->notempty || grid->empty == grid->square
		|| grid->notempty == grid->square)
		return (0);
	if (grid->empty <= 31  || grid->notempty <= 31 || grid->square <= 31 )
		return (0);
	return (1);
}
