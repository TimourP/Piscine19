/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_result2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:56:02 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/26 18:13:28 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

int  check_suffix(unsigned int count, t_num **dict, int index, char *num)
{
    char *suff;
    unsigned int i;
    int value;

    i = -1;
    value = 1;
    if (count == 1)
        return 1;
    if (!(suff = malloc(sizeof(char) * (count + 1))))
        return 0;
    while (++i < count)
        suff[i] = '0';
    suff[0] = '1';
    suff[count] = 0;
    value *= check_in_dict(dict, suff);
    if (test_if_end(index, num))
        write(1, " ", 1);
    free(suff);
    return (value);
}