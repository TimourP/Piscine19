/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 16:21:46 by timour            #+#    #+#             */
/*   Updated: 2020/09/27 20:14:59 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi_base(char *str, char *base, int size);

int		ft_checkbase(char *base)
{
	int i;
	int j;

	i = -1;
	while (base[++i])
		if (base[i] == '-' || base[i] == '+')
			return (0);
	if (i <= 1)
		return (0);
	i = -1;
	while (base[++i])
	{
		j = i;
		while (base[j++])
		{
			if (base[j] == base[i] && i != j)
				return (0);
		}
	}
	i = -1;
	while (base[++i])
		;
	return (i);
}

int		next_nbr_len(unsigned int n, unsigned int base_size)
{
	if (n < base_size)
		return (1);
	return (1 + next_nbr_len(n / base_size, base_size));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char			*dest;
	unsigned int	nb;
	int				base_len;
	int				i;
	int				n;

	n = ft_checkbase(base_from);
	if (!(n && (base_len = ft_checkbase(base_to))))
		return (NULL);
	n = ft_atoi_base(nbr, base_from, n);
	nb = (n < 0) ? -n : n;
	i = next_nbr_len(nb, base_len);
	i += (n < 0) ? 1 : 0;
	if (!(dest = malloc((i + 1) * sizeof(char))))
		return (NULL);
	dest[i] = 0;
	while (i--)
	{
		dest[i] = base_to[nb % base_len];
		nb /= base_len;
	}
	if (n < 0)
		dest[0] = '-';
	return (dest);
}
