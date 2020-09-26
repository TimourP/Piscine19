/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 16:43:14 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/26 17:22:09 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

int		is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

void	ft_puttextnumber(char *str)
{
	int i;
	int space;

	i = -1;
	space = 0;
	while (str[++i])
	{
		if (is_space(str[i]))
		{
			if (!space)
			{
				space = 1;
				write(1, &str[i], 1);
			}
		}
		else
		{
			write(1, &str[i], 1);
			space = 0;
		}
	}
	
}