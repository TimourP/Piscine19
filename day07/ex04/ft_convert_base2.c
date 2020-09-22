/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:48:19 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/16 17:04:32 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_baselen(char *base, int *count)
{
	int i;

	i = -1;
	while (base[++i])
		;
	*count = i;
}

int		test_error(char *base)
{
	int i;
	int j;

	i = -1;
	while (base[++i])
		if (base[i] == '-' || base[i] == '+')
			return (1);
	if (i <= 1)
		return (1);
	i = -1;
	while (base[++i])
	{
		j = i;
		while (base[j++])
		{
			if (base[j] == base[i] && i != j)
				return (1);
		}
	}
	return (0);
}

int     count_next_base(int basecount, int nbr)
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

char	*ft_putnbr_base(int nbr, char *base)
{
	unsigned int	num;
	int				basecount;
    char            *dest;
    int             destsize;
    int             neg;
    int             i;

    ft_baselen(base, &basecount);
    destsize = count_next_base(basecount, nbr);
    neg = 0;
	if (test_error(base))
		return (NULL);
	if (nbr < 0)
	{
		neg = 1;
        destsize++;
		num = 0 - nbr;
	}
	else
		num = nbr;
	i = -1;
    dest = malloc(sizeof(char) * destsize);
    while (++i < destsize)
    {
        dest[destsize - i - 1] = base[num % basecount];
        num = num / basecount;
    }
    dest[i] = 0;
    return (dest);
}
