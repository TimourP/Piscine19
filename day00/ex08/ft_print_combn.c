/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 12:35:56 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/10 16:55:18 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_string(char *pointeur, char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
	{
		pointeur[i] = str[i];
	}
}

void	print_list(int *arr, int n)
{
	char	nub[10];
	int		i;

	ft_string(nub, "0123456789");
	i = -1;
	while (++i < n + 1)
	{
		write(1, &nub[arr[i]], 1);
	}
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

void	init_arr(int *arr, int size)
{
	int i;

	i = -1;
	while (++i < size + 1)
	{
		arr[i] = i;
	}
}

void	ft_print_combn(int n)
{
	int main_array[10];
	int i;

	n--;
	i = -1;
	while (++i < n + 1)
	{
		main_array[i] = i;
	}
	print_list(main_array, n);
	while (main_array[0] != 9 - n)
	{
		new_step(main_array, n);
	}
}
