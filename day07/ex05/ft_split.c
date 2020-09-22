/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 19:23:02 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/17 09:28:50 by tpetit           ###   ########.fr       */
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

void	ret_world(char **dest, char *str, char *charset)
{
	int i;
	int j;
	char *currdst;
	int currwordcount;
	int currword;

	i = -1;
	currword = 0;
	currwordcount = 0;
	while (str[++i])
	{
		if (!is_in_list(charset, str[i]) && str[i + 1])
			currwordcount++;
		else if (currwordcount)
		{
			j = -1;
			if (str[i + 1] == 0)
			{
				currwordcount++;
				i++;
			}
			currdst = malloc(sizeof(char) * (currwordcount + 1));
			while (++j < currwordcount)
			{
				currdst[j] = str[i - currwordcount + j];
			}
			currdst[j] = 0;
			dest[currword] = currdst;
			currword++;
			currwordcount = 0;
		}
	}
	
}

char	**ft_split(char *str, char *charset)
{
	char **dest;
	int count;

	count = count_words(str, charset);
	
	if (!(dest = malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	if (count)
		ret_world(dest, str, charset);
	dest[count] = 0;
	return (dest);
}
