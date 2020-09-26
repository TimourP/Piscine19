/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 04:32:57 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/26 07:01:19 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

char	*find_name(t_num **dict, int nb);

void	write_billions(int nbr, t_num **dict, int totnum)
{
	if (nbr)
	{
		write_units(nbr, dict, totnum);
		ft_putstr(" ");
		ft_putstr(find_name(dict, 1000000000));
	}
}

void	write_millions(int nbr, t_num **dict, int totnum)
{
	if (nbr)
	{
		write_units(nbr, dict, totnum);
		ft_putstr(" ");
		ft_putstr(find_name(dict, 1000000));
	}
}

void	write_thousands(int nbr, t_num **dict, int totnum)
{
	if (nbr)
	{
		write_units(nbr, dict, totnum);
		ft_putstr(" ");
		ft_putstr(find_name(dict, 1000));
	}
}

void	write_units(int nbr, t_num **dict, int totnum)
{
	if (nbr / 100)
	{
		ft_putstr(find_name(dict, nbr / 100));
		ft_putstr(" hundred");
	}
	if (nbr % 100 < 20 && nbr && nbr != 100)
	{
		if (totnum > 100)
			ft_putstr(" ");
		ft_putstr(find_name(dict, nbr % 100));
	}
	else if (nbr && nbr != 100)
	{
		ft_putstr(" ");
		ft_putstr(find_name(dict, nbr % 100 - nbr % 10));
		ft_putstr(" ");
		ft_putstr(find_name(dict, nbr % 10));
	}
	else if (totnum == 0)
		ft_putstr(find_name(dict, 0));
}

char	*find_name(t_num **dict, int nb)
{
	int i;

	i = -1;
	while (dict[++i])
		if (dict[i]->nbr == nb)
			return (dict[i]->text_nbr);
	return ("NULL");
}
