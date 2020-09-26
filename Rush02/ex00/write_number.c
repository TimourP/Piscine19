/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 04:06:06 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/26 04:41:33 by tpetit           ###   ########.fr       */
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
    write_billions(nbr / 1000000000, file_name);
    write_millions((nbr % 1000000000) / 1000000, file_name);
    write_thousands((nbr % 1000000) / 1000, file_name);
    write_units(nbr % 1000, file_name);
}