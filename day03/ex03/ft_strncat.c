/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 15:35:49 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/14 19:14:53 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int i;
	unsigned int dstsize;

	i = -1;
	dstsize = 0;
	while (dest[++i])
		dstsize++;
	i = -1;
	while (src[++i] && nb--)
		dest[dstsize + i] = src[i];
	dest[dstsize + i] = '\0';
	return (dest);
}
