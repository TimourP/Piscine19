/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 13:38:39 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/18 18:49:43 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		tot_len(int size, char **strs, char *step)
{
	int i;
	int j;
	int count;

	i = -1;
	count = 0;
	while (++i < size)
	{
		j = -1;
		while (strs[i][++j])
		{
			count++;
		}
	}
	i = -1;
	while (step[++i])
		;
	count += i * (size - 1);
	return (count);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int srcsize;
	int dstsize;

	i = -1;
	srcsize = 0;
	dstsize = 0;
	while (src[++i] != '\0')
		srcsize++;
	i = -1;
	while (dest[++i] != '\0')
		dstsize++;
	i = dstsize - 1;
	while (++i < srcsize + dstsize)
		dest[i] = src[i - dstsize];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *step)
{
	char	*dest;
	int		i;

	dest = malloc(sizeof(char) * tot_len(size, strs, step));
	i = -1;
	dest[0] = 0;
	if (size == 0)
		return ("");
	while (++i < size)
	{
		ft_strcat(dest, strs[i]);
		if (i < size - 1)
			ft_strcat(dest, step);
	}
	return (dest);
}
