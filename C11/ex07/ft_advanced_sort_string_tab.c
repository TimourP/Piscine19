/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 14:55:47 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/21 15:00:45 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
		;
	return (i);
}

void	ft_swap(char **s1, char **s2)
{
	char *temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int i;
	int size;

	i = -1;
	size = ft_count(tab);
	while (++i < size - 1)
	{
		if (cmp(tab[i], tab[i + 1]) > 0)
		{
			ft_swap(&tab[i], &tab[i + 1]);
			i = -1;
		}
	}
}
