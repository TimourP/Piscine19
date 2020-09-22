/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:09:13 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/11 17:16:33 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	init_count(char *str1, char *str2, int *count1, int *count2)
{
	int i;

	i = -1;
	while (str1[++i])
		*count1 = *count1 + 1;
	i = -1;
	while (str2[++i])
		*count2 = *count2 + 1;
}

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int value;
	int strcount;
	int findcount;

	if (*to_find == '\0')
		return (str);
	init_count(str, to_find, &strcount, &findcount);
	i = -1;
	while (++i < strcount - findcount)
	{
		value = 1;
		j = -1;
		while (j++ < findcount - 1)
		{
			if (str[i + j] != to_find[j])
				value = 0;
		}
		if (value)
			return (&str[i]);
	}
	return (NULL);
}