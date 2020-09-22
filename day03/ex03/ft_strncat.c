/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 15:35:49 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/14 14:54:22 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int i;
	unsigned int dstsize;

	i = -1;
	dstsize = 0;
	while (dest[++i] != '\0')
		dstsize++;
	i = dstsize - 1;
	while (++i < nb + dstsize && src[i - dstsize])
		dest[i] = src[i - dstsize];
	dest[i] = '\0';
	return (dest);
}
