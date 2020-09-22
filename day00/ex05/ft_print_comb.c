/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 12:34:52 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/09 13:45:32 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_str(char *str, char *oldstr)
{
	int i;

	i = -1;
	while (str[i++] != '\0')
		str[i] = oldstr[i];
}

void	print_list(int *arr)
{
	char	nub[10];
	int		i;

	ft_str(nub, "0123456789");
	i = -1;
	while (i++ < 3)
		write(1, &nub[arr[i]], 1);
	if (arr[0] != 7)
		write(1, ", ", 2);
}

void	new_step(int *arr)
{
	if (arr[2] < 9)
		arr[2]++;
	else if (arr[1] < 8)
	{
		arr[1]++;
		arr[2] = arr[1] + 1;
	}
	else if (arr[0] < 7)
	{
		arr[0]++;
		arr[1] = arr[0] + 1;
		arr[2] = arr[1] + 1;
	}
	print_list(arr);
}

void	ft_print_comb(void)
{
	int main_array[3];
	int i;

	i = -1;
	while (i++ < 3)
	{
		main_array[i] = 0;
	}
	i = -1;
	while (main_array[0] != 7)
	{
		new_step(main_array);
	}
}
