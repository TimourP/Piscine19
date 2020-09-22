/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 13:38:39 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/20 10:08:11 by tpetit           ###   ########.fr       */
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

int count_tot_size(int size, char **strs, char *sep)
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

char *ft_strjoin(int size, char **strs, char *sep)
{
	int i;
	int destsize;
	char *dest;

	i = -1;
	destsize = count_tot_size(size, strs, sep);
	if(!(dest = malloc(sizeof(char) * destsize)))
		return (NULL);
	dest[0] = 0;
	while (++i < size)
	{
		ft_strcat(dest, strs[i]);
		if (i != size - 1)
			ft_strcat(dest, sep);
	}
	return (dest);
}