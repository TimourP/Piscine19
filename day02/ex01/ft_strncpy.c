/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 21:39:26 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/10 10:49:56 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int i;
	int end;

	end = 1;
	i = -1;
	while (++i < n)
	{
		if (src[i] != '\0' && end)
		{
			dest[i] = src[i];
		}
		else if (end && src[i] == '\0')
		{
			dest[i] = '\0';
			end = 0;
		}
		else
			dest[i] = '\0';
	}
	return (dest);
}