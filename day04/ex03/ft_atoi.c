/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 23:08:29 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/14 14:18:26 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void		ft_charok(char *str, int min, int *max)
{
	int i;

	i = min - 1;
	while (str[++i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
		{
			*max = i;
			return ;
		}
	}
	*max = i;
}

void		ft_pass_space(char *str, int *mini)
{
	int stop;
	int i;

	i = -1;
	stop = 0;
	while (str[++i] && !stop)
	{
		if (str[i] == ' ' && !stop)
			*mini = *mini + 1;
		else
			stop = 1;
	}
}

void		ft_space_sign(char *str, int *sign, int *min)
{
	int i;
	int mini;
	int stop;

	mini = 0;
	ft_pass_space(str, &mini);
	i = mini - 1;
	stop = 0;
	while (str[++i] && !stop)
	{
		if ((str[i] == '-' || str[i] == '+') && !stop)
		{
			if (str[i] == '-')
				*sign = !*sign;
			mini++;
		}
		else
			stop = 1;
	}
	*min = mini;
}

long		ft_tenmult(int times)
{
	int		i;
	long	count;

	i = -1;
	count = 1;
	while (++i < times)
		count *= 10;
	return (count);
}

int			ft_atoi(char *str)
{
	int		i;
	long	num;
	int		neg;
	int		min;
	int		max;

	num = 0;
	neg = 0;
	ft_space_sign(str, &neg, &min);
	ft_charok(str, min, &max);
	i = min - 1;
	while (++i < max)
	{
		num += (str[i] - '0') * ft_tenmult(max - i - 1);
	}
	if (neg)
		num = -num;
	i = num;
	return (i);
}
