/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 20:11:07 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/27 20:14:17 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_in_base(char c, char *base)
{
	int i;

	i = -1;
	while (base[++i])
		if (c == base[i])
			return (i);
	return (-1);
}

int		ft_atoi_base(char *str, char *base, int size)
{
	int i;
	int n;
	int neg;

	neg = 0;
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
