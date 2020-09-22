/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 12:35:17 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/09 14:00:37 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_list(int *arr)
{
	char	nub[10] = "0123456789";
	int		i;

	i = -1;
	while (i++ < 2)
	{
		write(1, &nub[arr[i] / 10], 1);
		write(1, &nub[arr[i] % 10], 1);
		if (i == 0)
			write(1, " ", 2);
	}
	if (arr[0] != 98)
		write(1, ", ", 2);
}

void	new_step(int *arr)
{
	if (arr[1] < 99)
		arr[1]++;
	else if (arr[0] < 99)
	{
		arr[0]++;
		arr[1] = arr[0] + 1;
	}
	print_list(arr);
}

void	ft_print_comb2(void)
{
	int main_array[2] = {0, 0};
	int i;

	i = -1;
	while (main_array[0] != 98)
	{
		new_step(main_array);
	}
}
