/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 13:38:39 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/20 19:04:50 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

int		count_tot_size(int size, char **strs, char *sep)
{
	int i;
	int count;
	int sepcount;

	i = -1;
	count = 0;
	sepcount = 0;
	while (sep[++i])
		sepcount++;
	i = -1;
	while (++i < size)
		count += ft_strlen(strs[i]);
	count += sepcount * (size - 1);
	count++;
	return (count);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = -1;
	while (src[++i])
	{
		dest[i] = src[i];
	}
	dest[i] = 0;
	return (&dest[0]);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		count;
	char	*dest;

	count = count_tot_size(size, strs, sep);
	if (!(dest = malloc(count * sizeof(char))))
		return (NULL);
	i = -1;
	count = 0;
	while (++i < size)
	{
		ft_strcpy(dest + count, strs[i]);
		count += ft_strlen(strs[i]);
		if (i != size - 1)
		{
			ft_strcpy(dest + count, sep);
			count += ft_strlen(sep);
		}
	}
	return (dest);
}
