/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 04:06:06 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/26 04:21:50 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

void write_numbers(char *file_name, char *number)
{
    int nbr;

    nbr = ft_atoi(number);
    if (nbr < 0)
    {
        ft_putstr("error\n");
        return ;
    }
    printf("%i : %s\n", nbr, file_name);
}