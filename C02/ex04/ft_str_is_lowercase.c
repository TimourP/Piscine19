/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 08:22:49 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 18:58:11 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_lowercase(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (!(97 <= str[i] && str[i] <= 122))
			return (0);
	}
	return (1);
}
