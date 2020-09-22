/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 22:05:11 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/19 12:59:30 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int *dest;
	int destsize;

	if (min < max)
		destsize = max - min;
	else
	{
		*range = (NULL);
		return (0);
	}
	if (!(dest = malloc(destsize * sizeof(int))))
		return (-1);
	i = -1;
	while (++i < destsize)
	{
		dest[i] = min + i;
	}
	*range = dest;
	return (destsize);
}
