/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 13:38:39 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/22 08:10:45 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = 0;
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		count;
	char	*dest;

	i = -1;
	count = 0;
	while (++i < size)
		count += ft_strlen(strs[i]);
	if (size > 0)
		count += (size - 1) * ft_strlen(sep);
	if (!(dest = malloc((count + 1) * sizeof(char))))
		return (NULL);
	i = -1;
	count = 0;
	while (++i < size)
	{
		ft_strcpy(dest + count, strs[i]);
		count += ft_strlen(strs[i]);
		if (i < size - 1)
			count += dest + count + ft_strlen(sep) - ft_strcpy(dest + count, sep);
	}
	dest[count] = 0;
	return (dest);
}
