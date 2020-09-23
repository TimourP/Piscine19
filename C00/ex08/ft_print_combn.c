/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 13:35:28 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/23 13:41:49 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int g_tab[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int g_count = 0;

void	init_grid(int n, int from)
{
	int i;

	i = -1;
	while (++i < from)
	{
		g_tab[8 - i] = n - i - 1;
	}
}

void	print_grid(n)
{
	int i;
	char c;

	i = -1;
	c = 0;
	while (++i < n)
	{
		c = g_tab[9 - n + i] + '0';
		write(1, &c, 1);
	}
	if (g_tab[9 - n] != 10 - n)
		write(1, ", ", 2);
}

void	reinit_grid(int val)
{
	int i;

	i = -1;
	while (++i < g_count)
	{
		g_tab[8 - i] = val + g_count - i;
	}
}

void	next_step(int n)
{
	while (g_tab[8 - g_count] == 9 - g_count)
		g_count++;
	g_tab[8 - g_count] += 1;
	reinit_grid(g_tab[8 - g_count]);
	g_count = 0;
	print_grid(n);
}

void	ft_print_combn(int n)
{
	if (n < 1 || n > 9)
		return ;
	init_grid(n, n);
	print_grid(n);
	while (g_tab[9 - n] != 10 - n)
		next_step(n);
}

int main(void)
{
	ft_print_combn(3);
	return (0);
}