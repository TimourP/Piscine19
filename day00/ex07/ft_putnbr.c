/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 12:35:42 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/09 19:14:51 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_string(char *pointeur, char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
	{
		pointeur[i] = str[i];
	}
}

void	ft_putnbr(int nb)
{
	char	int_2_string[12];
	char	possint[10];
	int		count;

	ft_string(possint, "0123456789");
	count = 0;
	while (nb > 0)
	{
		int_2_string[11 - count] = possint[nb % 10];
		nb = nb / 10;
		count++;
	}
	write(1, int_2_string, 12);
}

int		main(void)
{
	ft_putnbr(1837);
	return (0);
}
