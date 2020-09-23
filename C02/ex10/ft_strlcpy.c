/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 09:40:04 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/23 17:49:44 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int srcsize;
	unsigned int j;

	srcsize = ft_strlen(src);
	if (srcsize + 1 < size)
	{
		j = -1;
		while (++j < srcsize + 1)
			dest[j] = src[j];
	}
	else if (size)
	{
		j = -1;
		while (++j < size - 1)
			dest[j] = src[j];
		dest[j] = '\0';
	}
	return (srcsize);
}
