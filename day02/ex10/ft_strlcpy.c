/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 09:40:04 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/10 10:54:06 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int i;
	int end;

	end = 0;
	i = -1;
	while (++i < size - 1)
	{
		if (src[i] != '\0' && !end)
			dest[i] = src[i];
		else if (src[i] == '\0')
			end = 1;
		if (end)
			dest[i] = '\0';
	}
	return (0);
}

int		main(void)
{
	char str[10];

	ft_strlcpy(str, "hello", 10);
	printf("%d, %d, %d\n", str[5] == '\0', str[6] == '\0', str[7] == '\0');
	printf("%s", str);
	return (0);
}
