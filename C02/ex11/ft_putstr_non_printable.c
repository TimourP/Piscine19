/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 11:46:58 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/12 12:14:34 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	*hexbase;

	i = -1;
	while (str[++i])
	{
		if (str[i] <= 31)
		{
			hexbase = "0123456789abcdef";
			ft_putchar('\\');
			ft_putchar(hexbase[str[i] / 16]);
			ft_putchar(hexbase[str[i] % 16]);
		}
		else
			ft_putchar(str[i]);
	}
}
