/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 19:23:02 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/16 22:19:09 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		is_in_list(char *list, char c)
{
	int i;

	i = -1;
	while (list[++i])
	{
		if (list[i] == c)
			return (1);
	}
	return (0);
}

int		count_words(char *str, char *charset)
{
	int i;
	int inword;
	int count;

	i = -1;
	inword = 0;
	count = 0;
	while (str[++i])
	{
		if (is_in_list(charset, str[i]))
		{
			if (inword)
			{
				inword = 0;
				count++;
			}
		}
		else if (!inword)
			inword = 1;
	}
	if (i > 0 && !is_in_list(charset, str[i - 1]))
		count++;
	return (count);
}

char	*ret_world(char *str, char *charset, int num)
{
	int i;
	char *dest;
	int numcount;

	i = -1;
	numcount = 0;
}

char	**ft_split(char *str, char *charset)
{
	char **dest;
	char *temp;
	int i;
	int count;

	count = count_words(str, charset);
	dest = malloc(sizeof(char *) * (count + 1));
	i = -1;
	while (++i < count)
	{
		ret_world(str, charset, i);
	}
	return (dest);
}
