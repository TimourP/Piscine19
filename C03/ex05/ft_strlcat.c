/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 18:01:30 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/15 08:19:20 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			ft_str_len(char *s1, char *s2, unsigned int *c, unsigned int *d)
{
	int i;

	i = -1;
	*c = 0;
	*d = 0;
	while (s1[++i])
	{
		*c = *c + 1;
	}
	i = -1;
	while (s2[++i])
	{
		*d = *d + 1;
	}
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	countsrc;
	unsigned int	countdst;
	unsigned int	tot;

	ft_str_len(src, dest, &countsrc, &countdst);
	if (countdst > size)
		tot = size + countsrc;
	else
		tot = countsrc + countdst;
	i = countdst - 1;
	while (++i < size - 1 && src[i - countdst])
	{
		dest[i] = src[i - countdst];
	}
	if (dest[i])
		dest[i] = '\0';
	return (tot);
}