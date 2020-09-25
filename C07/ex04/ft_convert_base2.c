/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 08:40:34 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/25 08:47:57 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_baselen(char *base, int *count)
{
	int i;

	i = -1;
	while (base[++i])
		;
	*count = i;
}

int		count_next_base(int basecount, unsigned int nbr)
{
	int count;

	count = 0;
	while (nbr > 0)
	{
		nbr = nbr / basecount;
		count++;
	}
	return (count);
}

void	ft_fill_up_dest(char *dest, int *s_n_c, unsigned int num, char *base)
{
	int i;
	int neg;

	i = -1;
	neg = !s_n_c[1];
	if (num == 0)
	{
		dest[0] = base[0];
		return ;
	}
	while (++i < s_n_c[0])
	{
		if (s_n_c[1])
		{
			s_n_c[1] = 0;
			dest[0] = '-';
		}
		else
		{
			dest[s_n_c[0] - i - neg] = base[num % s_n_c[2]];
			num = num / s_n_c[2];
		}
	}
	dest[i] = 0;
}

char	*ft_putnbr_base(int nbr, char *base)
{
	unsigned int	num;
	char			*dest;
	int				s_n_c[3];

	s_n_c[1] = 0;
	if (nbr < 0)
	{
		s_n_c[1] = 1;
		num = 0 - nbr;
	}
	else
		num = nbr;
	ft_baselen(base, &s_n_c[2]);
	s_n_c[0] = count_next_base(s_n_c[2], num);
	if (s_n_c[1])
		s_n_c[0] = s_n_c[0] + 1;
	dest = malloc(sizeof(char) * (s_n_c[0] + 1));
	ft_fill_up_dest(dest, s_n_c, num, base);
	return (dest);
}