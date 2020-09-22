/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 09:22:46 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/12 11:31:03 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_if_not_alpha(char c)
{
	if (!((97 <= c && c <= 122) || (65 <= c && c <= 90)))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
	{
		if ((97 <= str[i] && str[i] <= 122) || (65 <= str[i] && str[i] <= 90))
		{
			if (i > 0)
			{
				if (check_if_not_alpha(str[i - 1]))
				{
					if (97 <= str[i] && str[i] <= 122)
						str[i] -= 32;
				}
				else
				{
					if (65 <= str[i] && str[i] <= 90)
						str[i] += 32;
				}
			}
			else if (97 <= str[i] && str[i] <= 122)
				str[i] -= 32;
		}
	}
	return (str);
}
