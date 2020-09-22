/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 18:01:30 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/12 13:22:47 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void ft_str_len(char *src1, char *src2,unsigned int *c1,unsigned int *c2)
{
	int i;

	i = -1;
	*c1 = 0;
	*c2 = 0;
	while(src1[++i])
	{
		*c1 = *c1 + 1;
	}
	i = -1;
	while(src2[++i])
	{
		*c2 = *c2 + 1;
	}
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int				i;
	unsigned int	countsrc;
	unsigned int	countdst;

	ft_str_len(dest, src, &countdst, &countsrc);
	//printf("%d\n", count);
	return (countsrc + countdst);
}

int				main(void)
{
	char	dest[30] = "ta";
	char	dest2[30] = "ta";
	char	src[40] = "hellohellohellohellohellohellohello";
	int		i;

	i = -1;
	
	
	printf("%lu\n", ft_strlcat(dest, src, 30));
	printf("%s\n", dest);
	while (++i < 30)
		printf("%d ", dest[i] == '\0');
	printf("\n");
	i = -1;
	printf("%lu\n", strlcat(dest2, src, 30));
	printf("%s\n", dest2);
	while (++i < 30)
		printf("%d ", dest2[i] == 'h');
	printf("\n");
}
