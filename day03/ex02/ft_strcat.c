/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 08:27:15 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/11 09:20:04 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char    *ft_strcat(char *dest, char *src)
{
    int i;

    i = -1;
    while (src[++i] != '\0')
    {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}

int     main(void)
{
    char dest[10];
    char dest2[10];
    char src[10] = "tomtom";
    char src2[10] = "tomtom";

    strcat(dest, src);
    printf("%s\n", dest);
    printf("%c, %c, %c, %c\n", dest[0], dest[4], dest[5], dest[9]);
    printf("%d, %d, %d, %d\n", dest[0] == '\0', dest[4] == '\0', dest[5] == '\0', dest[9] == '\0');
    printf("------------------------\n");
    ft_strcat(dest2, src2);
    printf("%s\n", dest2);
    printf("%c, %c, %c, %c\n", dest2[0], dest2[4], dest2[5], dest2[9]);
    printf("%d, %d, %d, %d\n", dest2[0] == '\0', dest2[4] == '\0', dest2[5] == '\0', dest2[9] == '\0');
}