/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 21:03:49 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/21 08:42:14 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *dest;

	i = -1;
	if (!(dest = malloc(length * sizeof(int))))
		return (NULL);
	while (++i < length)
		dest[i] = f(tab[i]);
	return (dest);
}
