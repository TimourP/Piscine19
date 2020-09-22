/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 09:40:04 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/12 11:46:07 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	count;
	int				end;

	end = 0;
	i = -1;
	count = 0;
	while (src[++i])
		count++;
	i = -1;
	while (++i < size)
	{
		if (src[i] != '\0' && !end)
			dest[i] = src[i];
		else
			end = 1;
		if (end)
		{
			dest[i] = '\0';
		}
	}
	return (count);
}
