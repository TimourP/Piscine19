/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 07:42:48 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/21 08:44:34 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int i;
	int count;

	count = 0;
	i = -1;
	while (++i < length)
		if (f(tab[i]))
			count++;
	return (count);
}
