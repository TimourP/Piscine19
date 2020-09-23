/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 12:35:56 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/23 12:00:04 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_list(int *arr, int n)
{
	int		i;

	i = -1;
	while (++i < n + 1)
		ft_putchar(arr[i] + '0');
	if (arr[0] != 9 - n)
		write(1, ", ", 2);
}

void	new_step(int *arr, int n)
{
	int count;
	int i;

	count = n;
	while (arr[count] == 9 - (n - count))
	{
		count--;
	}
	arr[count] = arr[count] + 1;
	if (count != n)
	{
		i = -1;
		while (++i < n - count)
		{
			count += 1;
			arr[count] = arr[count - 1] + 1;
		}
	}
	print_list(arr, n);
}

void	ft_print_combn(int n)
{
	int main_array[10];
	int i;

	i = -1;
	if (n >= 1 && n <= 9)
	{
		while (++i < n)
		{
			main_array[i] = i;
		}
		print_list(main_array, n - 1);
		while (main_array[0] != 10 - n)
			new_step(main_array, n - 1);
	}
}
