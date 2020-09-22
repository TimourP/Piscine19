/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 09:40:04 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/10 17:45:20 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int i;
	int end;

	end = 0;
	i = -1;
	while (++i < size - 1)
	{
		if (src[i] != '\0' && !end)
			dest[i] = src[i];
		else if (src[i] == '\0')
			end = 1;
		if (end)
		{
			dest[i] = '\0';
			break ;
		}
	}
	return (0);
}
