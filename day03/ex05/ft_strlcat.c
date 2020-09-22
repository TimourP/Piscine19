/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 18:01:30 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/11 18:25:08 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (dest[++i] != '\n')
		count++;
	printf("%d\n", count);
	return (0);
}

int				main(void)
{
	char	dest[30];
	char	src[40] = "hellohellohellohellohellohello";
	int		i;

	i = -1;
	ft_strlcat(dest, src, 10);
	while (++i < 30)
		printf("%d ", dest[i] == '\0');
	printf("\n");
	i = -1;
	strlcat(dest, src, 30);
	printf("%s\n", dest);
	while (++i < 30)
		printf("%d ", dest[i] == '\0');
	printf("\n");
}
