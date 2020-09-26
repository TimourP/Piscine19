/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:05:40 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/26 15:19:45 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

void write_suffix(unsigned int count, t_num **dict)
{
    char *suff;
    unsigned int i;

    i = -1;
    if (count == 1)
        return ;
    if (!(suff = malloc(sizeof(char) * (count + 1))))
        return ;
    while (++i < count)
        suff[i] = '0';
    suff[0] = '1';
    suff[count] = 0;
    write(1, find_in_dict(dict, suff), ft_strlen(find_in_dict(dict, suff)));
    free(suff);
}