/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timour <timour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 16:21:46 by timour            #+#    #+#             */
/*   Updated: 2020/09/27 16:30:39 by timour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		check_in_base(char c, char *base)
{
	int i;

	i = -1;
	while (base[++i])
		if (c == base[i])
			return (i);
	return (-1);
}

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

int		ft_atoi_base(char *str, char *base, int size)
{
	int i;
	int n;
	int neg;

	neg = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
		if (*str++ == '-')
			neg = !neg;
	n = 0;
	while ((i = check_in_base(*str++, base)) >= 0)
		n = n * size + i;
	return (neg ? -n : n);
}

int		next_nbr_len(unsigned int n, unsigned int base_size)
{
	if (n < base_size)
		return (1);
	return (1 + ft_nbrlen(n / base_size, base_size));
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