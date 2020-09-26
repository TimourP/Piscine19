/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:43:10 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/26 18:41:32 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

int	check_units(char c, char d, char u, t_num **dict);
int		check_char_in_dict(t_num **dict, char c);
int check_non_printable(t_num **dict);

int		check_result(t_num **dict, char *nbr)
{
	unsigned int count;
	unsigned int i;
	int mainval;

	mainval = 1;
	if (!check_non_printable(dict))
		return (-1);
	count = ft_strlen(nbr);
	i = 0;
	if (count % 3 == 1)
	{
		mainval *= check_units('0', '0', nbr[i], dict);
		i++;
	}    
	else if (count % 3 == 2)
	{
		mainval *= check_units('0', nbr[i], nbr[i + 1], dict);
		i += 2;
	}
	if (i != 0)
	{
		if (count > 3)
		mainval *= check_suffix(count - i + 1, dict, i, nbr);
	}
	while (i < count)
	{
		mainval *= check_units(nbr[i], nbr[i + 1], nbr[i + 2], dict);
		if ((nbr[i] != '0' || nbr[i + 1] != '0' || nbr[i + 2] != '0'))
			mainval *= check_suffix(count - i - 2, dict, i, nbr);
		i += 3;
	}
	return (mainval);
}

int check_units(char c, char d, char u, t_num **dict)
{
	char arr[3] = {d, u, '\0'};
	int mainval;

	mainval = 1;
	if (c != '0')
	{
		mainval *= check_char_in_dict(dict, c);
		mainval *= check_in_dict(dict, "100");
	}
	if (d < '2')
	{
		if (d < '1')
		{
			if (u != '0')
				mainval *= check_char_in_dict(dict, u);
		}
		else
			mainval *= check_in_dict(dict, arr);
	}
	else
	{
		arr[1] = '0';
		mainval *= check_in_dict(dict, arr);
		if (u != '0')
		{
			mainval *= check_char_in_dict(dict, u);
		}   
	}
	return (mainval);
}

int check_char_in_dict(t_num **dict, char c)
{
	int i;

	i = -1;
	while (dict[++i])
	{
		if (c == dict[i]->nbr[0] && !(dict[i]->nbr[1]))
			return (1);
	}
	return (0);
}

int check_in_dict(t_num **dict, char *str)
{
	int i;

	i = -1;
	while (dict[++i])
	{
		if (!ft_strcmp(str, dict[i]->nbr))
			return (1);
	}
	return (0);
}

int check_non_printable(t_num **dict)
{
	int i;
	int j;

	i = -1;
	while (dict[++i])
	{
		j = -1;
		while (dict[i]->text_nbr[++j])
			if (dict[i]->text_nbr[j] <= 31 && !is_space(dict[i]->text_nbr[j]))
				return (0);
	}
	return (1);
}