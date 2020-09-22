/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 21:39:26 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/09 22:09:46 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int count;
	int i;

	count = 0;
	i = -1;
	while (src[++i] != '\0')
	{
		count++;
	}
	i = -1;
	while (i++ < count)
	{
		if (i < n)
			dest[i] = src[i];
		else
			dest[i] = '\0';
	}
	return (&dest[0]);
}

int main(void)
{
	char str[10];

	ft_strncpy(str, "hello", 3);
	printf("%d, %d, %d\n",str[3] == '\0', str[4] == '\0', str[5] == '\0');
	printf("%s", str);
}