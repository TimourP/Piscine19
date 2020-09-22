/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 08:27:15 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/11 14:58:23 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int i;

	i = -1;
	while (src[++i] != '\0')
	{
		dest[i] = src[i];
		printf("hellobro\n");
	}
	printf("%d\n", i);
	dest[i] = '\0';
	return (dest);
}
