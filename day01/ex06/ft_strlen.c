/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 20:40:53 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/09 20:42:00 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (str[i++] != '\0')
	{
		count++;
	}
	count--;
	return (count);
}
