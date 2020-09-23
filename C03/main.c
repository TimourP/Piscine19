/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 14:15:09 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/23 14:21:07 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int main(void)
{
    char dest[100] = "";
    char dest2[100] = "";
    char src[100] = "hello";

    printf("%d\n", ft_strlcat(dest, src, 100) == strlcat(dest2, src, 100));
    printf("%s\n", dest);
}